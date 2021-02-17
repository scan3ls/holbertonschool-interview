#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

# valid bytes
single_byte   = int("01000000", 2)
continue_byte = int("10100000", 2)
two_byte      = int("11010000", 2)
three_byte    = int("11101000", 2)
four_byte     = int("11110100", 2)
not_overlong  = [
    360, 242, 234, 220
]

#Invalid bytes
five_byte     = int("11111000", 2)
full_byte     = int("11111111", 2)
over_byte     = int("111110000", 2)
# Euro Sign
overlong_byte = [
    int("11110000", 2),
    int("10000010", 2),
    int("10000010", 2),
    int("10101100", 2)
]

print(
    "Bytes: ", single_byte, continue_byte,
    two_byte, three_byte, four_byte,
    five_byte, full_byte, over_byte
)
print("Valid tests: Return Should = True")

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, -33]
print("\nGiven single bytes\n\t", validUTF8(data))

data = [
    single_byte, single_byte,
     single_byte, single_byte,
     single_byte
]
print("\nAll single byte characters\n\t", validUTF8(data))

data = [
    two_byte, continue_byte,
    two_byte, continue_byte,
    single_byte
]
print("\nComplete 2-byte characters\n\t", validUTF8(data))

data = [
    three_byte, continue_byte, continue_byte,
    three_byte, continue_byte, continue_byte,
    single_byte
]
print("\nComplete 3-byte characters\n\t", validUTF8(data))

data = [
    four_byte, continue_byte, continue_byte, continue_byte,
    four_byte, continue_byte, continue_byte, continue_byte,
    single_byte
]
print("\nComplete 4-byte characters\n\t", validUTF8(data))

data = []
print("\nEmpty data set\n\t", validUTF8(data))

data = not_overlong
print("\nNot overlong encoded character\n\t", validUTF8(data))

# ===============================================================
print("\n===================================")
print("\nInvalid Test: Return Should = False")

data = [
    continue_byte, continue_byte,
    continue_byte, continue_byte,
    continue_byte
]
print("\nOnly continuation bytes\n\t", validUTF8(data))

data = [
    two_byte
]
print("\nIncomplete 2-byte character\n\t", validUTF8(data))

data = [
    three_byte
]
print("\nIncomplete 3-byte character\n\t", validUTF8(data))

data = [
    four_byte
]
print("\nIncomplete 4-byte character\n\t", validUTF8(data))

data = [
    four_byte, continue_byte, continue_byte
]
print("\nIncomplete 4-byte character w/ continuation-bytes\n\t", validUTF8(data))

data = [
    single_byte, continue_byte
]
print("\nSingle byte trailed by a continuation byte\n\t", validUTF8(data))

data = [five_byte]
print("\nCharacter longer than 4 bytes\n\t", validUTF8(data))

data = [full_byte]
print("\nAll bits are 1\n\t", validUTF8(data))

data = [over_byte]
print("\nbyte more than 8 bits\n\t", validUTF8(data))

data = overlong_byte
print("\noverlong encoding\n\t", validUTF8(data))
