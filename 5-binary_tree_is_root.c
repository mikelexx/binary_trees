#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a given node is root.
 * @node: pointer to the node to check.
 * Return: return 1 if node is a root, otherwise 0 including\
 * node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	else
		return (0);
}