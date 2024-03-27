#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node:  a pointer to the node to find the uncle.
 * Return: return a pointer to the uncle node or If node is NULL, return NULL\
 * or If node has no uncle, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *tmp = node;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	tmp = node->parent;
	if (tmp->parent == NULL)
		return (NULL);
	if (tmp->parent->left == tmp)
		return (tmp->parent->right);
	else
		return (tmp->parent->left);
}
