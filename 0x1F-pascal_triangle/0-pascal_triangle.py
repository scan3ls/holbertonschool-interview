#!/usr/bin/python3
""" defines a function for return a list reprsentation of Pascal's triangle """

def pascal_triangle(n):
    """ return a list representation of Pascal's triangle """
    if n <= 0:
        return []

    triangle, layers = [[1]], n - 1

    while layers > 0:
        layer = []

        for index, value in enumerate(triangle[-1]):
            left = triangle[-1][index - 1] if index != 0 else 0
            layer.append(left + value)

        layer.append(1)
        triangle.append(layer)
        layers -= 1

    return triangle
