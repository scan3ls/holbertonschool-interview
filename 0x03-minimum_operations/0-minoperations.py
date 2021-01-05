#!/usr/bin/python3
"""
    Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
"""


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

    clip = Clipboard(n)
    nums = clip.get_nums()

    # print(nums)
    for index, num in enumerate(nums):
        # print(clip)
        try:
            next_num = nums[index + 1]
        except IndexError:
            break

        if num * 2 == next_num:
            clip.copy()

        clip.paste()
    return clip.get_operations()
