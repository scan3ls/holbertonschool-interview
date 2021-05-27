#!/usr/bin/python3
from copy import copy


def rotate_2d_matrix(matrix):
    n = len(matrix)
    nums = []

    for column in range(0, n):
        for row in range(n - 1, -1, -1):
            nums.append(matrix[row][column])

    for row in range(0, n):
        for column in range(0, n):
            value = nums.pop(0)
            matrix[row][column] = value
