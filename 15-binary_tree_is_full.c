#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: a pointer to the tree node of the tree to check.
 * Return: If tree is NULL, your function must return 0\
 * other wise return 1 if its full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full_left = 0, full_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right == NULL)
		return (0);
	if (tree->right && tree->left == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	full_left = binary_tree_is_full(tree->left);
	full_right = binary_tree_is_full(tree->right);
	return (full_left && full_right);
}
