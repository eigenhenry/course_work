from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

with open('key.bin', 'rb') as file:
    key = file.read()
with open('iv.bin', 'rb') as file:
    iv = file.read()

with open('ciphertext_ecb.bin', 'rb') as file:
    ciphertext_ecb = file.read()
with open('ciphertext_cbc.bin', 'rb') as file:
    ciphertext_cbc = file.read()
with open('ciphertext_cfb.bin', 'rb') as file:
    ciphertext_cfb = file.read()
with open('ciphertext_ofb.bin', 'rb') as file:
    ciphertext_ofb = file.read()

cipher_ecb = AES.new(key, AES.MODE_ECB)
decrypted_ecb = unpad(cipher_ecb.decrypt(ciphertext_ecb), AES.block_size)

cipher_cbc = AES.new(key, AES.MODE_CBC, iv)
decrypted_cbc = unpad(cipher_cbc.decrypt(ciphertext_cbc), AES.block_size)

cipher_cfb = AES.new(key, AES.MODE_CFB, iv)
decrypted_cfb = cipher_cfb.decrypt(ciphertext_cfb)

cipher_ofb = AES.new(key, AES.MODE_OFB, iv)
decrypted_ofb = cipher_ofb.decrypt(ciphertext_ofb)

with open('decrypted_ecb.txt', 'wb') as file:
    file.write(decrypted_ecb)
with open('decrypted_cbc.txt', 'wb') as file:
    file.write(decrypted_cbc)
with open('decrypted_cfb.txt', 'wb') as file:
    file.write(decrypted_cfb)
with open('decrypted_ofb.txt', 'wb') as file:
    file.write(decrypted_ofb)
