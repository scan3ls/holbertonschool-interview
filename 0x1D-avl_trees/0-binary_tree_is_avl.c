#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if tree is an avl tree
 * @tree: binary tree to check
 *
 * Return: 1 if tree is avl tree else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;
	int balance;
	int isRightAVL, isLeftAVL;

	if (!tree)
		return 1;

	leftHeight = get_height(tree->left);
	rightHeight = get_height(tree->right);

	balance = rightHeight - leftHeight;
	if (balance < -1 || balance > 1)
		return 0;

	isLeftAVL = binary_tree_is_avl(tree->left) * 1;
	isRightAVL = binary_tree_is_avl(tree->right) * 1;

	return (isLeftAVL && isRightAVL);
}

/**
 * get_height - gets the height of a node in a binary tree
 * @tree: node of a binary tree
 *
 * Return: height of node tree
 */
int get_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = get_height(tree->left) + 1;
	right = get_height(tree->right) + 1;

	return (left > right) ? left : right;
}
