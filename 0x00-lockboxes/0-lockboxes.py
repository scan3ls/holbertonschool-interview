#!/usr/bin/python3


def canUnlockAll(boxes):

    #  Open and empty keys from first box
    keys = boxes[0]
    boxes[0] = []
    opening = True

    #  main loop
    while opening:

        opening = False
        #  Open and empty keys from boxes with current keys
        for key in keys:
            if boxes[key] is []:
                continue

            keys += boxes[key]
            boxes[key] = []
            opening = True

        # check if all boxes are empty
        empty = True
        for box in boxes:
            if box != []:
                empty = False
                break

        if empty:
            return True

        # check if boxes with keys are empty
        empty = True
        for key in keys:
            if boxes[key] != []:
                empty = False

        if empty:
            return False

        # Throw away duplicate keys
        keys = list(dict.fromkeys(keys))

    #  Default return
    return False
