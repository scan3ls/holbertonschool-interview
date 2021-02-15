#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """ Validator """
    for num in data:
        b = "{0:b}".format(num)

        if len(b) > 8:
            return False

    return True
