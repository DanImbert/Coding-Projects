from cs50 import get_float

def get_cents():
    dollars = get_float("Enter amount in dollars: ")
    while dollars < 0.0:
        dollars = get_float("Enter a non-negative amount in dollars: ")
    cents = round(dollars * 100)
    return cents


def calculate_coins(cents):
    coins = [25, 10, 5, 1]
    count = 0
    for coin in coins:
        count += cents // coin
        cents %= coin
    return count


def main():
    cents = get_cents()
    coins = calculate_coins(cents)
    print(coins)


if __name__ == "__main__":
    main()

