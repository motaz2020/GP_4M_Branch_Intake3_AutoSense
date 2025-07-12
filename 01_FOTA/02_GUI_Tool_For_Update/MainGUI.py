"""
@file
@brief FOTA (Firmware Over The Air) Application
@author Ahmed Atef Mahmoud
@date Oct 10, 2023
@see https://github.com/sherifkhadr
"""

from tkinter import *
from tkinter.filedialog import askopenfilename
import pyrebase as Pyrebase
import time
from subprocess import call
from intelhex import IntelHex
from tkinter import PhotoImage
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


def encrypt_file(input_file, output_file, key, iv):
    """
    Encrypt a file using AES Cipher
    """
    with open(input_file, 'rb') as file:
        plaintext = file.read()

    plaintext = pad(plaintext)

    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(plaintext) + encryptor.finalize()

    with open(output_file, 'wb') as file:
        file.write(ciphertext)


# Firebase configuration
config = {
    "apiKey": "AIzaSyA_tphZJ2jvNfTvv50Hluu1lB4v3n1X-WM",
    "authDomain": "fota-9c846.firebaseapp.com",
    "databaseURL": "https://fota-9c846-default-rtdb.firebaseio.com",
    "projectId": "fota-9c846",
    "storageBucket": "fota-9c846.appspot.com",
    "messagingSenderId": "1039801453963",
    "appId": "1:1039801453963:web:84e763d050677264d3738e"
}

firebase = Pyrebase.initialize_app(config)
db = firebase.database()
auth = firebase.auth()
storage = firebase.storage()

# Hex Record Encryption (AES Cipher)
key = b'\xf1;\xb9O\xec\xa5eC\x97\xe6\xe6~\xf6\xf4\x98O'  # 128-bit key
iv = b'=\xa7\xa4\xcb\xffeI`\x98:0\x0c\xc2\x1bl\n'

path = ""
final_path = ""
url = ""

flag = 0

data = db.update({"NewUpdate": 0})


def button_action():
    global path
    global final_path
    input_path.delete(0, "end")
    path = askopenfilename(initialdir=".\\",
                           filetypes=(("Text File", "*.txt"), ("All Files", "*.*")),
                           title="Choose a file."
                           )

    output_file_path = 'Encrypted_hexfile.bin'
    encrypt_file(path, output_file_path, key, iv)
    final_path = output_file_path
    input_path.insert(0, final_path)


def upload():
    global url
    global flag
    data = db.child("NewUpdate").get()
    if data.val() == 1:
        status_label.configure(text="Server is busy")
    else:
        status_label.configure(text="Uploading ...")

        # Updating header
        data = db.update({"NewUpdate": 1})
        # Uploading file
        x = storage.child("code.txt").put(final_path)
        status_label.configure(text="Uploaded")


# GUI
window = Tk()
window.geometry("525x300+200+100")
window.title("FOTA ...")

bgimg = PhotoImage(file="wallpaper.png")
myLabel = Label(window, image=bgimg, font=55, fg='#FF0000', bg='#4682B4')
myLabel.place(x=0, y=0, relwidth=1, relheight=1)

for i in range(0, 8):
    window.columnconfigure(i, minsize='5m')

for i in range(0, 8):
    window.rowconfigure(i, minsize='5m')

label1 = Label(window, text="Choose file :",
               font=60, bg="#121212", fg='#FFFFFF')
label1.grid(row=3, column=1)

label2 = Label(window, text="Process status : ",
               font=40, bg="#121212", fg='#FFFFFF')
label2.grid(row=6, column=1)

status_label = Label(window, text="IDLE", font=40,
                     bg="#292827", fg='#FFFFFF')
status_label.grid(row=6, column=2)

input_path = Entry(window, width=20, font=30)
input_path.grid(row=3, column=2)

browes_button = Button(window, text="Browse", font=20,
                       command=button_action, bd=10, bg='#FE5025')
browes_button.grid(row=3, column=4)

upload_button = Button(window, text="Upload", font=30,
                       command=upload, bd=10, bg='#FE5025')
upload_button.grid(row=4, column=1, columnspan=7)

window.mainloop()
