#include "binary_trees.h"
/**
 * binary_tree_insert_right - a node as the right-child of another node.
 * Description: if parent already has a right-child, the new node must\
 * take its place and the old right-child  must be set as the right-child\
 * of the new node.
 * @parent:  pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *child = NULL, *old_child = NULL;

	if (parent == NULL)
		return (NULL);
	child = binary_tree_node(parent, value);
	if (child == NULL)
		return (NULL);
	child->n = value;
	if (!parent->right)
		parent->right = child;
	else
	{
		old_child = parent->right;
		child->right = old_child;
		old_child->parent = child;
		parent->right = child;
	}
	return (child);
}
