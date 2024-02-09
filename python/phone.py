#implement phone book
from cs50 import get_string
import sys

people = {
    "Carter": "044004040",
    "David": "381550905"
}

# search through phone book

person = input("Person:")
for people in person:
    print(f"{person} is in the phone book")
    sys.exit(0)

