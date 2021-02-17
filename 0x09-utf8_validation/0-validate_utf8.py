#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """ Validator """

    while (data):
        character = getCharacter(data)
        if character is False:
            return False
    return True


def getCharacter(data):
    octet_seq = []
    byte = "{:08b}".format(data.pop(0))

    if byte[0] == '0':
        return byte

    octet_seq.append(byte)

    start = byte.split('0')[0]
    length = start.count('1') - 1
    if length == 0 or length >= 4:
        return False

    for _ in range(length):
        if data == []:
            return False
        byte = "{:08b}".format(data.pop(0))
        if byte[0:2] != "10":
            return False

        octet_seq.append(byte)

    return octet_seq
