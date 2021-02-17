#!/usr/bin/python3
"""
    UTF-8 Validation
"""


def validUTF8(data):
    """ Validator """

    line = []
    for i in data:
        if i < 0:
            return False
        try:
            line.append( i.to_bytes(1, 'big') )
        except:
            line.append( i.to_bytes(2, 'big') )
    line = b''.join(line)
    try:
        line.decode('utf-8')
    except UnicodeDecodeError as e:
        # print(line, e)
        return False
    return True
