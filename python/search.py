import sys


#list of names
library = ["David", "Ron", "Seth"]

# ask for name
name = input("What name are you searching for?\n")
if name in library:
    print(f"{name} is in library")


# search for name