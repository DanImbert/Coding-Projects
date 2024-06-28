def main():
    # Prompt for height input and validate
    while True:
        height_input = input("Height: ")

        if height_input == "" or height_input == "foo":
            print("Invalid input. Please enter a valid height.")
            continue

        try:
            height = int(height_input)
            if height < 1 or height > 8:
                print("Invalid input. Height must be between 1 and 8.")
            else:
                break
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

    # Print pyramid pattern
    for row in range(height):
        for hash in range(height):
            if row + hash >= height - 1:
                print("#", end="")
            else:
                print(" ", end="")

        print("  ", end="")

        for hash in range(height + row + 1, height, -1):
            print("#", end="")

        print()

if __name__ == "__main__":
    main()
