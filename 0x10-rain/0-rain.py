#!/usr/bin/python3
""" Find space between walls"""


def build_walls(walls):
    """ find water levels """
    levels = []
    for height in range(max(walls), 0, -1):
        level = []
        for index, wall in enumerate(walls):
            if wall >= height:
                level.append(str(index))
            else:
                level.append(' ')
        levels.append(level.copy())

    return levels


def rain(walls):
    """ rain function Finds space between walls """
    if walls == []:
        return 0

    levels = build_walls(walls)
    collected = 0

    for level in levels:
        s1 = "".join(level)
        # print(s1.replace(' ', '_'))
        s1 = s1.strip()
        # print(s1.replace(' ', '_'))
        collected += s1.count(' ')

    return collected
