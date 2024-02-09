# cash problem

cents = int(input("Change: "))


cents = round(cents*100)
count = 0

quarters = 25
dimes = 10
nickels = 5
pennies = 1

# Calculate the number of each type of coin needed
count += cents // quarters
cents %= quarters

count += cents // dimes
cents %= dimes

count += cents // nickels
cents %= nickels

count += cents // pennies
cents %= pennies

print("Number of coins in change: ", count)