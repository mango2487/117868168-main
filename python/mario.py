j = 0
e = 0
n = 0

while True:
    try:
        n = int(input("Give me ya number dog: "))
        if n <= 0 or n >= 9:
            n = int(input("Give me ya number dog (1-8): "))
        else:
            break
    except ValueError:
        print("Invalid please input positive int")

# for i in range(n):
#     print("#  #")
#     j += 1
#     if j > 0 or j <= n:
#         print(" ", "#" * (n - 1), "#  #", "#" * (n - 1))


# for i in range(n):
#     print(" " * (n - e - 1), "#", end="")
#     j += 1
#     e += 1
#     if j > 0 and j <= n:
#         print("#" * (j - 1),"", "#" * (j))

for i in range(n):
    print(" " * (n - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))
