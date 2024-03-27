#include "binary_trees.h"
/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node.
 * Description: If parent already has a left-child, the new node must take its\
 * place, and the old left-child must be set as the left-child of the new node.
 * @parent:  pointer to the node to insert the left-child in
 * @value: value to store in the new node.
 * Return: pointer to the created node, or NULL on failure or if parent is \
 * NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *child = NULL, *old_child = NULL;

	if (parent == NULL)
		return (NULL);
	child = binary_tree_node(parent, value);
	if (child == NULL)
		return (NULL);
	child->n = value;
	if (!parent->left)
		parent->left = child;
	else
	{
		old_child = parent->left;
		old_child->parent = child;
		parent->left = child;
		child->left = old_child;
	}

	return (child);
}
