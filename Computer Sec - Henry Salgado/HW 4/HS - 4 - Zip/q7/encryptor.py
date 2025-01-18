from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes

with open('sample.txt', 'rb') as file:
    plaintext = file.read()

key = get_random_bytes(16)
iv = get_random_bytes(16)

with open('key.bin', 'wb') as file:
    file.write(key)
with open('iv.bin', 'wb') as file:
    file.write(iv)

cipher_ecb = AES.new(key, AES.MODE_ECB)
ciphertext_ecb = cipher_ecb.encrypt(pad(plaintext, AES.block_size))

cipher_cbc = AES.new(key, AES.MODE_CBC, iv)
ciphertext_cbc = cipher_cbc.encrypt(pad(plaintext, AES.block_size))

cipher_cfb = AES.new(key, AES.MODE_CFB, iv)
ciphertext_cfb = cipher_cfb.encrypt(plaintext)

cipher_ofb = AES.new(key, AES.MODE_OFB, iv)
ciphertext_ofb = cipher_ofb.encrypt(plaintext)

with open('ciphertext_ecb.bin', 'wb') as file:
    file.write(ciphertext_ecb)
with open('ciphertext_cbc.bin', 'wb') as file:
    file.write(ciphertext_cbc)
with open('ciphertext_cfb.bin', 'wb') as file:
    file.write(ciphertext_cfb)
with open('ciphertext_ofb.bin', 'wb') as file:
    file.write(ciphertext_ofb)
