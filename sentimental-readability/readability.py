# TODO
text = input("Text: ")

word = text.split()
word_count = len(word)

# counting letter
lettercount = 0
for wor in text:
    if wor.isalpha():
        lettercount += 1


# counting avg letter
L = lettercount / word_count * 100

sentence_count = 0

for i in text:
    if i in [".", "!", "?"]:
        sentence_count += 1

# counting avg sentence
S = sentence_count / word_count * 100

grade = int(round(0.0588 * L - 0.296 * S - 15.8))

if grade <= 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")

