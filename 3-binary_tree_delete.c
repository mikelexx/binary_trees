#include "binary_trees.h"
/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree:  pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *parent = tree, *left = NULL, *right = NULL;

	if (tree == NULL)
		return;
	left = parent->left;
	right = parent->right;
	free(parent);
	binary_tree_delete(left);
	binary_tree_delete(right);
}
