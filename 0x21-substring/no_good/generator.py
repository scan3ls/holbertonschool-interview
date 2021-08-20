#!/usr/bin/python3
import sys

class Node:
    def __init__(self, value, remaining):
        self.value = value
        self.remaining = remaining
        self.children = self.set_children()

    def set_children(self):
        remaining = self.remaining.copy()
        children = []

        for num in remaining:
            copy = remaining.copy()
            value = copy.pop(copy.index(num))
            new_value = self.value.copy()
            new_value.append(value)
            node = Node(new_value, copy)
            children.append(node)

        return children

    def __str__(self):
        return "{}".format(self.value)

def get_leaves(node, memo=[]):
    if len(node.children) == 0:
        memo.append(node.value)
        return memo

    for child in node.children:
        memo = get_leaves(child)

    return memo

arguments = sys.argv
num = int(arguments[1])

root = Node([], [n for n in range(num)])
leaves = get_leaves(root)

with open('word_schema_data.txt', 'w') as f:
    for leaf in leaves:
        f.write(":".join([str(n) for n in leaf]))
        f.write('\n')
