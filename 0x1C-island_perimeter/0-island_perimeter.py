#!/usr/bin/python3
""" Find the perimeter of an island """


def find_water(grid, row, pos):
    """ findin' dah waza """
    if row - 1 < 0:
        up = 1
    else:
        up = 0 if grid[row - 1][pos] else 1

    try:
        down = 0 if grid[row + 1][pos] else 1
    except IndexError:
        down = 1

    if pos - 1 < 0:
        left = 1
    else:
        left = 0 if grid[row][pos - 1] else 1

    try:
        right = 0 if grid[row][pos + 1] else 1
    except IndexError:
        right = 1

    return up + down + left + right


def island_perimeter(grid):
    """ Find the perimeter of an island """
    shore = 0
    for index, row in enumerate(grid):
        for pos, value in enumerate(row):
            if value:
                shore += find_water(grid, index, pos)
    return shore

if __name__ == "__main__":
    # grid = [
    #     [0, 0, 0, 0, 0, 0],
    #     [0, 1, 0, 0, 0, 0],
    #     [0, 1, 0, 0, 0, 0],
    #     [0, 1, 1, 1, 0, 0],
    #     [0, 0, 0, 0, 0, 0]
    # ]
    grid = [
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1]
    ]
    print(island_perimeter(grid))
