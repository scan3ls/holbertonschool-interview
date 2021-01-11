# 0x04. sandpiles

## Introduction
This repository is used for project based learning in Holberton.
Youtube video - [Numberphile: Sandpiles](https://www.youtube.com/watch?v=1MtEUErz7Gg)

### Write a Function that copmutes the sum of two sandpiles.
- You can assume that both `grid1` and `grid2` are individually **stable**
- A sandpile is considered **stable** when none of its cells contains more than 3 grains
- When your function is done, `grid1` must be **stable**
- `grid1` must be printed before each toppling round, only if it is unstable (See example)
- You’re not allowed to allocate memory dynamically

Example

    3 3 3   1 3 1
    3 3 3 + 3 3 3
    3 3 3   1 3 1
    =
    4 6 4
    6 6 6
    4 6 4
    =
    2 5 2
    5 6 5
    2 5 2
    =
    4 2 4
    2 6 2
    4 2 4
    =
    0 5 0
    5 2 5
    0 5 0
    =
    2 1 2
    1 6 1
    2 1 2
    =
    2 2 2
    2 2 2
    2 2 2