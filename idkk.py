import hashlib

def hash_text(text):
    # Create an MD5 hash object
    md5_hash = hashlib.md5()
    
    # Convert the text to bytes and update the hash object
    md5_hash.update(text.encode('utf-8'))
    
    # Get the hexadecimal digest of the hash
    hex_digest = md5_hash.hexdigest()
    
    return hex_digest

# Example usage
# text = "Hello, World!"
# hashed_text = hash_text(text)
# print(f"Original text: {text}")
# print(f"MD5 hash: {hashed_text}")
dictPass = {}
dictHash = {}


# passwords = "123456,123456789,111111,password,qwerty,soccer10".split(",")
# passwordSearch = "qwerty"
# hashSearch = "5f4dcc3b5aa765d61d8327deb882cf99"

passwords = input().split(",")
passwordSearch = input()
hashSearch = input()

for i in range(len(passwords)):
    print(passwords[i], hash_text(passwords[i]))
    dictPass[passwords[i]] = hash_text(passwords[i])
    dictHash[hash_text(passwords[i])] = passwords[i]
    
# for key in dictPass:
#     if hashSearch in dictPass[key]:
#         print(f"cbrc_CTF({dictPass[key]})")

# for key in dictHash:
#     if passwordSearch in dictHash[key]:
#         print(f"cbrc_CTF({dictHash[key]})")

print(f"cbrc_CTF({dictPass[passwordSearch]})")
print(f"cbrc_CTF({dictHash[hashSearch]})")
