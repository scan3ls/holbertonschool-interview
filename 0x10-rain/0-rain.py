#!/usr/bin/python3
""" Find space between walls"""


def build_walls(walls):
    """ build a 2d representation of the walls """
    levels = []
    for height in range(max(walls), 0, -1):
        level = []
        for index, wall in enumerate(walls):
            if wall >= height:
                level.append('|')
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
        # print(s1)  # Prints walls
        # print(s1.replace(' ', '_'))  # walls w/ spaces as '_'
        s1 = s1.strip()
        # print(s1.replace(' ', '_'))  # print step to counting collected rain
        collected += s1.count(' ')

    return collected
