"""
Create a python program that reads through that document looking for various words as provided by the user  and then print out the sub-flag. That flag is the flag for this challenge is the combination of the words

* wojus
* comte
* janty

the flag will look like the following: 

cbrc_CTF(flag1:flag2:flag3)

Use this code as a primer. 

"""
obj = {}

with open('flags', 'r') as flag_reader:
    flags = flag_reader.readlines()
    for flag in flags:
        if flag.strip() in ["wojus", "comte", "janty"]:
            obj[flag.strip()] = flag.strip()
        
print(obj)
# print(f"cbrc_CTF({obj.get('wojus', '')}:{obj.get('compte', '')}:{obj.get('janty', '')})")



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
    #print(passwords[i], hash_text(passwords[i]))
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



// 

loginput = input()
arr = loginput.split(",")

for i in range(len(arr)):
    parts = arr[i].split(" ")
    status_code = parts[0]
    method = parts[1]
    path = parts[2]
    
    if status_code =='500':
        print(f"cbrc_CTF({i}:{status_code}:{method}:{path})")




// 



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
    #print(passwords[i], hash_text(passwords[i]))
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
