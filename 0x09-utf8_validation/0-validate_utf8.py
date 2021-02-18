#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """
    --------------
    Method: validUTF8
    --------------
    Description:
        check if list of ints can be converted
        into valid UTF-8 character sequence
    Args:

    --------------
    """

    chars = makeBytes(data)

    if chars is False:
        return False

    try:
        chars.decode('utf-8')
    except UnicodeDecodeError as e:
        # print(line, e)
        return False

    return True


def makeBytes(data):
    """
    --------------
    Method: makeBytes
    --------------
    Description:
        convert list of int into a byte string
    Args:
        list of ints
    --------------
    """
    line = []

    for i in data:
        if i < 0:
            return False
        try:
            line.append(i.to_bytes(1, 'big'))
        except OverflowError:
            line.append(i.to_bytes(2, 'big'))

    return b''.join(line)
