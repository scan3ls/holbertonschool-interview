#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if tree is an avl tree
 * @tree: binary tree to check
 *
 * Return: 1 if tree is avl tree else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_AVL(tree));
}

/**
 * is_AVL - check if tree is an avl tree
 * @tree: binary tree to check
 *
 * Return: 1 if tree is avl tree else 0
 */
int is_AVL(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;
	int balance, isBST;
	int isRightAVL, isLeftAVL;

	if (!tree)
		return (1);

	leftHeight = get_height(tree->left);
	rightHeight = get_height(tree->right);

	balance = rightHeight - leftHeight;
	if (balance < -1 || balance > 1)
		return (0);

	if (!is_BST(tree, -1, -1))
		return (0);

	isLeftAVL = is_AVL(tree->left) * 1;
	isRightAVL = is_AVL(tree->right) * 1;

	return (isLeftAVL && isRightAVL);
}

/**
 * is_BST - check if tree is a binary search tree
 * @tree: binary tree to check
 * @low: low value for child nodes or -1
 * @high: high value for child nodes or -1
 *
 * Return: 1 if tree is avl tree else 0
 */
int is_BST(const binary_tree_t *tree, int low, int high)
{
	if (!tree)
		return (1);

	if (low != -1 && tree->n <= low)
		return (0);

	if (high != -1 && tree->n >= high)
		return (0);

	if (is_BST(tree->right, tree->n, high) == 0)
		return (0);

	if (is_BST(tree->left, low, tree->n) == 0)
		return (0);

	return (1);
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

	return ((left > right) ? left : right);
}