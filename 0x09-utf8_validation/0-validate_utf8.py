#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """ Validator """
    try:
        bytes(data)
    except ValueError:
        return False

    return True
