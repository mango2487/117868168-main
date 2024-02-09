#save names and numebrs to csv file
import csv

# get name and number
name = input("name: ")
number = input("number: ")

#open file
with open ("phonebook.csv", 'a') as file:
    writer = csv.writer(file)
    writer.writerow([name, number])

#print to f

# not working idk why