#!/usr/bin/python3
""" Return fewest number of coins for change """


def invalidArguments(coins, total):
    """ validate args"""
    if isinstance(coins, list) is False:
        return True
    if isinstance(total, int) is False:
        return True
    if total <= 0:
        return True

    if list(map(lambda x: isinstance(x, int), coins)).count(False):
        return True

    return False


def makeChange(coins, total):
    if invalidArguments(coins, total):
        return 0

    coins.sort()
    coins.reverse()
    counter = 0

    while coins != []:
        divisor = coins[0]
        if divisor <= 0:
            break

        if total < divisor:
            coins.pop(0)
            continue

        result = int(total / divisor)
        counter = counter + result
        total = total - (result * divisor)

    return counter if total == 0 else -1

if __name__ == "__main__":
    print(makeChange(1, 37))
    print(makeChange([1], 'yes'))
    print(makeChange([1, 'a', -1], 100))
    print(makeChange([1, 25, 2], 37))
    print(makeChange([1256, 54, 48, 16, 102], 1453))
    print(makeChange([1, 25, 0], 37))
