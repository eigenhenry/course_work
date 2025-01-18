
def caesar_encrypt(text, shift):
    
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    # I changed the indexing so that the shift is foward
    shifted_alphabet = alphabet[shift:] + alphabet[:shift]
    table = str.maketrans(alphabet, shifted_alphabet)
    return text.lower().translate(table)

#message
plaintext = "Programming is like cooking. Even if you follow the recipe perfectly, there's always a chance you'll end up with a big mess."

encrypted_message = caesar_encrypt(plaintext, 7)


print(f"Message: {encrypted_message}")
