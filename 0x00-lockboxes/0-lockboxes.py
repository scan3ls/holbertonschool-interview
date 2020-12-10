#!/usr/bin/python3


def canUnlockAll(boxes):

    # get keys from firstbox and empty
    keys = boxes[0]
    boxes[0] = []

    usedKeys = []
    opening = True

    # repeat
    while opening:
        # throw away dupe keys
        keys = list(dict.fromkeys(keys))
        newKeys = []
        # check if already opend
        for key in keys:
            if key in usedKeys:
                continue

            # check if key is valid
            try:
                box = boxes[key]
            except:
                continue

            # goto box with key and empty. Add keys to unused keys
            newKeys += box
            boxes[key] = []

        # Update keys
        usedKeys += keys
        keys = newKeys

        # check if still have keys
        if keys == []:
            opening = False

    # check if all boxes are empty
    # print("boxes", boxes)
    for box in boxes:
        if box != []:
            return False

    return True
