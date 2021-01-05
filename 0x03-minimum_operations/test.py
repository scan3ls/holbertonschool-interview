#!/usr/bin/python3
"""
    Main file for testing
"""


def run(num, value):
    """
    --------------
    Method: run
    --------------
    Description:
        Import and rum function minOperations
        Print out the results
    Args:
        @num: Integer
            Input argument for function
            minOperations
        @value: Integer
            The expected output given
            num
    --------------
    """
    path = '0-minoperations'
    minOperations = __import__(path).minOperations
    output = minOperations(num)
    if (output == value):
        print("Test Passed!")
    else:
        print("\nTest Failed!")
        string = "Num: {}\nExpected: {}\nGot: {}\n".format(
            num, value, output
        )
        print(string)

# list of test values
tests = {
    -19: 0,
    1: 0,
    4: 4,
    9: 6,
    12: 7,
    16: 8,
    18: 8,
    39: 16,
    100: 14
}

for key in tests:
    run(key, tests[key])
