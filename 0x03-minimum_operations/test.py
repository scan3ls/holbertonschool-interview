#!/usr/bin/python3
"""
    Main file for testing
"""


def run(n):
    """
    --------------
    Method: run
    --------------
    Description:
        Import and rum function minOperations
        Print out the results
    Args:
        @n: Integer
            Input argument for function
            minOperations
    --------------
    """
    minOperations = __import__('0-minoperations').minOperations
    print(
        "Min number of operations to reach {} characters: {}".format(
            n, minOperations(n)
        )
    )


# list of test values
nums = [
    1, 4, 12,
    9, 16, 18,
    -100
]
nums.sort()
for n in nums:
    run(n)
