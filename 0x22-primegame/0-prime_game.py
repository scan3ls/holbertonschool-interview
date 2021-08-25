#!/usr/bin/python3
""" module doc """


def isMariaTurn(turn):
    """ return's if Maria's turn """
    return turn % 2 == 0


def isBenTurn(turn):
    """ returns if Ben's turn """
    return turn % 2 != 0


def primesUpTo(num):
    """ return all prime numbers up to num """
    primes = [1]
    for i in range(2, num + 1):
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            primes.append(i)

    return primes


def reduced(nums):
    """ for n in nums reduce n if n is a multiple of prime number """
    primes = primesUpTo(max(nums))

    def isMultiple(n):
        """ map function """
        primes_sorted = sorted(primes, reverse=True)
        for num in primes_sorted:
            if num == 1:
                return n
            if (n % num) == 0:
                return num

    reduced_nums = sorted(list(map(isMultiple, nums)))
    if reduced_nums[0] == 1:
        reduced_nums.pop(0)

    return set(reduced_nums)


def isWinner(x, nums):
    """ function docs """
    players = ("Maria", "Ben")
    wins = [0, 0]
    last_winner = None

    if x < 1 or len(nums) == 0:
        return None

    for game_round in set(nums):
        available_nums = list(filter(lambda n: n <= game_round, nums))
        reduced_nums = reduced(available_nums)
        if game_round < 2:
            wins[1] += 1
            continue
        turns = len(reduced_nums)
        if (isMariaTurn(turns)):
            wins[1] += 1
        if (isBenTurn(turns)):
            wins[0] += 1

        if wins[0] > wins[1]:
            last_winner = players[0]
        if wins[1] > wins[0]:
            last_winner = players[1]

    if wins[0] == wins[1]:
        return last_winner
    return players[wins.index(max(wins))]

# print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
