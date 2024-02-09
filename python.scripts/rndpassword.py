import random
import string
# This is a script that generates 18 char passwords
word_length = 18
# generate a list of letters, digits and some punctuation
components = [string.ascii_letters, string.digits, "!@#$%&"]
# flatten into list of characters
chars = []
for clist in components:
    for items in clist:
        chars.append(items)
def generate_password():
    #store the generated password
    password = []
    #choose a random thing from chars and join it to password
    for i in range(word_length):
        rchar = random.choice(chars)
        password.append(rchar)
    #return list of char into string
    return "".join(password)

print(generate_password())