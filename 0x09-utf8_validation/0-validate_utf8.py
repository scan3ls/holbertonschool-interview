#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """ Validator """

    while (data):
        isValid = getCharacter(data)

        if isValid is False:
            return False

    return True


def getCharacter(data):
    """ << >>  """
    num = data.pop(0)
    if num < 0:
        return False

    byte = "{:08b}".format(num)

    if byte[0] == '0':
        return True

    start = byte.split('0')[0]

    length = start.count('1') - 1
    if length == 0 or length >= 4:
        return False

    for _ in range(length):

        if data == []:
            return False

        num = data.pop(0)
        if num < 0:
            return False

        byte = "{:08b}".format(num)
        if byte[0:2] != "10":
            return False

    return True
