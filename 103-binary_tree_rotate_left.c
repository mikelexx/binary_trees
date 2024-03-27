#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on ab inary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child = NULL;

	if (tree == NULL)
		return (NULL);
	right_child = tree->right;
	if (right_child)
	{
		tree->right = right_child->left;
		if (right_child->left)
		{
			right_child->left->parent = tree;
		}
		right_child->left = tree;
		tree->parent = right_child;
		return (right_child);
	}
	return (tree);
}
