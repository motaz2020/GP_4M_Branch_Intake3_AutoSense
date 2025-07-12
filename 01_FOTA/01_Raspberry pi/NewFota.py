"""
@file
@brief FOTA (Firmware Over The Air) Flashing Python Script
@author Ahmed Atef Mahmoud
@date Oct 8, 2023
@see https://github.com/sherifkhadr
"""

import os
import firebase_admin
from firebase_admin import credentials, db, storage
import time
import serial
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend


def pad(text):
    """
    PKCS7 padding
    """
    block_size = 16
    padding_length = block_size - (len(text) % block_size)
    padding = bytes([padding_length] * padding_length)
    return text + padding


def unpad(text):
    """
    PKCS7 unpadding
    """
    padding_length = text[-1]
    return text[:-padding_length]


def decrypt_file(input_file, output_file, key, iv):
    """
    Decrypt a file using AES Cipher
    """
    with open(input_file, 'rb') as file:
        ciphertext = file.read()

    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    decryptor = cipher.decryptor()
    decrypted_text = decryptor.update(ciphertext) + decryptor.finalize()

    decrypted_text = unpad(decrypted_text)

    with open(output_file, 'wb') as file:
        file.write(decrypted_text)


# SOME Definitions AND Global VARIABLES
local_file_path = ''
final_path = ''
NewUpdate = 0
ReceiveReq = ''

# Set BuadRate On Both Sides rpi and stm, baud = 38400
Baud = 9600

# if Raspberrypi is Used:-
UART_Port = "/dev/serial0"

# Replace 'path/to/serviceAccountKey.json' with the path to your service account key file
cred = credentials.Certificate("fota-9c846-firebase-adminsdk-hnpv3-c89a484166.json")

# Initialize Firebase
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://fota-9c846-default-rtdb.firebaseio.com/',
    'storageBucket': "fota-9c846.appspot.com"
})

# Reference to the root of your Realtime Database
db_ref = db.reference('NewUpdate')

# Reading "NewUpdate" from Realtime Database
NewUpdate = db_ref.get()

# Keep Checking For Any Updates
while NewUpdate == 0:
    # Keep Checking For Any Updates
    while NewUpdate == 0:
        db_ref = db.reference('NewUpdate')
        # Keep Reading "NewUpdate" from Realtime Database
        NewUpdate = db_ref.get()

    # Check if Received Update
    if NewUpdate == 1:

        UART = serial.Serial(baudrate=Baud, port=UART_Port, parity="N", stopbits=1,
                             bytesize=serial.EIGHTBITS
                             )

        print("NewUpdate is processing: ...... >>> ", NewUpdate)  # Indcator To Start NewUpdate Process

        GetReady = 'm'  # Send Indicator To Stm32 To Get Ready for Receiving Update

        UART.write(GetReady.encode("utf-8"))   # Write 'm' over UART Serial Port

        ReceiveReq = UART.inWaiting()             # Check for remaining byte

        ReceiveReq = UART.read()                    # Read The Reply Form Stm32

        ReceiveReq = ReceiveReq.decode("utf-8")

        while ReceiveReq != 'q':
            ReceiveReq = UART.read()
            ReceiveReq = ReceiveReq.decode("utf-8")
            print("Request is Accepted: ...... >>> ", ReceiveReq)
        # Clear The Status Of NewUpdate In Realtime Database
        ClearNewUpdate = {'NewUpdate': 0}
        db_ref = db.reference('NewUpdate')
        db_ref.set(ClearNewUpdate)

        # Reference to your Cloud Storage bucket
        bucket = storage.bucket()

        # Specify the file to be downloaded from Cloud Storage
        cloud_storage_path = "code.txt"

        # Specify the local path where you want to save the downloaded file
        file = open("Encrypted_code.txt", "w")

        # Save The Encrypted File In Certain Path To Get Read And Decrypted
        local_file_path = os.path.expanduser('~/fota/Encrypted_code.txt')

        # Download the file from Cloud Storage
        blob = bucket.blob(cloud_storage_path)
        blob.download_to_filename(local_file_path)

        # Decrypt The Received Update File Then Send To Stm32 To Flashed
        # Define the AES key and mode
        key = b'\xf1;\xb9O\xec\xa5eC\x97\xe6\xe6~\xf6\xf4\x98O'  # 128-bit key
        iv = b'=\xa7\xa4\xcb\xffeI`\x98:0\x0c\xc2\x1bl\n'        # 128-bit iv
        decrypt_file(local_file_path, 'Decrypted_HexCode_File.txt', key, iv)  # Decrypted The Received File Then Write It in "Decrypted_HexCode_File.txt"
        final_path = 'Decrypted_HexCode_File.txt'
        print("Decryption is Successful")   # Make Sure The Hex Code File Decrypted Successfully

        # File is Ready To Be Flashed
        print("Ready for flashing processing: ......")
        time.sleep(0.5)  # Some Delay
        with open(final_path, "r") as FileHex:
            if (UART.is_open):
                print("Successfully")
            for Line in FileHex:
                for letter in Line:
                    UART.write(letter.encode("utf-8"))
                ReadAck = UART.inWaiting()             # Check for remaining byte
                ReadAck = UART.read(2)                    # Read The Reply Form Stm32
                ReadAck = ReadAck.decode("utf-8")
                print(Line)
                time.sleep(0.01)
                print(ReadAck)
            else:
                print("NOK")

            FileHex.close()

        print("Flashing Update Is Completed.")
        UART.close()

    else:
        # Do Nothing
        time.sleep(1)

# End Of Code /////////////////////////////////////////////////////////////////////////////////////////////////
