#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *parent, *new_node;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    parent = get_parent(*root);
    new_node = binary_tree_node(parent, value);
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    if (parent->n < new_node->n)
        new_node = swap(parent, new_node, root);
    
    return (new_node);
}

heap_t *swap(heap_t *parent, heap_t *child, heap_t **root)
{
    int temp;
    heap_t *node;

    if (parent == NULL)
        return (child);

    if (parent->n >= child->n)
        return (child);

    temp = parent->n;
    parent->n = child->n;
    child->n = temp;

    node = swap(parent->parent, child->parent, root);

    return (node);
}

heap_t *get_parent(heap_t *root)
{
    heap_t *left, *right, *parent;
    int h_left, h_right;

    if (root->left != NULL && root->right != NULL)
    {
        left = get_parent(root->left);
        right = get_parent(root->right);
    }
    if (root->left == NULL || root->right == NULL)
        return (root);
    
    parent = left->parent;
    for (h_left = 0; parent; h_left++)
        parent = parent->parent;

    parent = right->parent;
    for (h_right = 0; parent; h_right++)
        parent = parent->parent;

    if (h_left <= h_right)
        return (left);
    return (right);
}
