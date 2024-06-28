from cs50 import get_string

def main():
    # Get input text from user
    text = get_string("Text: ")

    # Count letters, words, and sentences
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calculate L and S
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Calculate Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Print the grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

def count_words(text):
    count = 1  # Assume at least one word
    for char in text:
        if char.isspace():
            count += 1
    return count

def count_sentences(text):
    count = 0
    for char in text:
        if char in [".", "!", "?"]:
            count += 1
    return count

if __name__ == "__main__":
    main()
