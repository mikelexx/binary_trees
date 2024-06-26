#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on\
 * on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child = NULL;

	if (tree == NULL)
		return (NULL);
	left_child = tree->left;
	if (left_child)
	{
		tree->left = left_child->right;
		if (left_child->right)
			left_child->right->parent = tree;
		left_child->right = tree;
		tree->parent = left_child;
		return (left_child);
	}
	return (tree);
}
