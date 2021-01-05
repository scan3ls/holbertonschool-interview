#!/usr/bin/python3
"""
    Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
"""


def get_root(n):
    """
    --------------
    Method: get_root
    --------------
    Description:
        Get the root of a given number
        and returns it or None is the
        root doesn't exist

    Args:
        @n: Integer
            Finding the root for
            this number.
    --------------
    """
    import math
    root = math.sqrt(n)
    return root if root % 1 == 0 else None


def get_half(n):
    """
    --------------
    Method: get_half
    --------------
    Description:
        Finds and returns the half
        of a number if that half
        is a solid integer or
        returns None.
    Args:
        @n: Integer
            Finding the half of this
            number.
    --------------
    """
    half = n / 2
    if half == 1:
        return None
    return half if half % 1 == 0 else None


def get_third(n):
    """
    --------------
    Method: get_third
    --------------
    Description:
        Finds and returns the third
        of a number if that third
        is a solid integer or
        returns None.
    Args:
        @n: Integer
            Finding the third of this
            number.
    --------------
    """
    third = n / 3
    if third == 1:
        return None
    return third if third % 1 == 0 else None


def get_nums(n, array):
    """
    --------------
    Method: get_nums
    --------------
    Description:
        Gets the progression of numbers
        from 1 to N using a copy & paste
        process
    Example:
        Given N: 9

        1 => Copy & Paste => 2 => Paste => 3
        => Copy & Paste => 6 => Paste => 9

        Result: [1, 2, 3, 6, 9]
    Args:
        @n: Integer
            Given Number
        @array: List of Integers
            List of numbers to be
            returned
    --------------
    """
    if n < 1:
        return array
    n = int(n)
    half = get_half(n)
    root = get_root(n)
    third = get_third(n)

    if half:
        array = get_nums((n-half), array)
    elif root:
        array = get_nums((n-root), array)
    elif third:
        array = get_nums((n-third), array)
    else:
        array = list(range(1, n))

    array.append(n)
    return array


def minOperations(n):
    """
    --------------
    Method: minOperations
    --------------
    Description:
        Counts the number of actions
        needed to get from 1 to N using
        a Copy Paste process.
        Return the count of actions or
        0 if no number of actions results
        in N
    Args:
        @n: Integer
        Target Final number
    --------------
    """
    from clipboard import Clipboard

    nums = []
    nums = get_nums(n, nums)
    clip = Clipboard()

    for index, num in enumerate(nums):
        try:
            next_num = nums[index + 1]
        except IndexError:
            break

        if num * 2 == next_num:
            clip.copy()

        clip.paste()
    # print(nums)
    return clip.get_operations()