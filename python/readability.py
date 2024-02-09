punctuation = {".", "!", "?"}

while True:
    text = input("Give me string: ")
    if any(p in text for p in punctuation):
        break
    else:
        print("The string must contain at least one '.', '!', or '?' punctuation.")


letter_count = sum(c.isalpha() for c in text)
word_count = len(text.split())
sentence_count = text.count(".") + text.count("?") + text.count("!")
# print(f"letters: {letter_count}\nwords: {word_count}\nsentences {sentence_count}")

# Coleman Liau Index
grade = (
    0.0588 * (letter_count / word_count * 100)
    - 0.296 * (sentence_count / word_count * 100)
    - 15.8
)

if grade < 1:
    print("Before Grade 1")

elif grade > 16:
    print("Grade 16+")

else:
    print("Grade", round(grade))

# // get a string input to be graded [Y]
# // implement function count_letters & sentence & word [Y]
# // plug into formula (index = 0.0588 * L - 0.296 * S - 15.8) [Y]
# // spit out result [Y]
