#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree:  pointer to the node to measure the depth.
 * Return: depth or If tree is NULL, your function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *curr = tree;
	size_t depth = 0;

	while (curr)
	{
		if (curr->parent)
			depth += 1;
		curr = curr->parent;
	}
	return (depth);
}
