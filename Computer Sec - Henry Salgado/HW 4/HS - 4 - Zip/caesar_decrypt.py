def caesar_decrypt(text, shift):
    
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    shifted_alphabet = alphabet[-shift:] + alphabet[:-shift]  # Rotate end to start
    table = str.maketrans(alphabet, shifted_alphabet)
    return text.translate(table)

# Message
text = "Tvsxigx csyv hexe amxl gevi erh geyxmsr. Epaecw ywi wxvsrk erh yrmuyi tewwasvhw jsv iegl eggsyrx, vikypevpc ythexi, erh oiit csyv hizmgiw erh wsjxaevi yt xs hexi"

# Most common letters in English to compare against
common_letters = 'etaoin'

# Trying different shifts to find the most plausible one
best_match = 0
for shift in range(26):
    decoded = caesar_decrypt(text, shift)
    match_count = sum(letter in decoded for letter in common_letters)
    if match_count > best_match:
        best_match = match_count
        best_shift = shift
        best_result = decoded

# Printing
print(f"Best shift: {best_shift}")
print(f"Decrypted message: {best_result}")
