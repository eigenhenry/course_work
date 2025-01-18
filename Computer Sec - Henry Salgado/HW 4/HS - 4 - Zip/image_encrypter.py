from Crypto.Cipher import AES
from Crypto import Random
import os

def encrypt_image(file_name, mode):
    with open(file_name, 'rb') as f:
        original = f.read()
    header, body = original[:54], original[54:]

    key = Random.new().read(16)
    iv = Random.new().read(AES.block_size)
    
    if mode == 'ECB':
        cipher = AES.new(key, AES.MODE_ECB)
    elif mode == 'CBC':
        cipher = AES.new(key, AES.MODE_CBC, iv)
    
    while len(body) % 16 != 0:
        body += b'\x00'

    encrypted_body = cipher.encrypt(body)

    with open(f'encrypted_{mode}_{file_name}', 'wb') as f:
        f.write(header + encrypted_body)

encrypt_image('pic_original.bmp', 'ECB')
encrypt_image('pic_original.bmp', 'CBC')
