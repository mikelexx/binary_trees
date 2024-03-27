#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary search tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: pointer to the created node, or NULL on failure.
 * Description: If the address stored in tree is NULL, the \
 * created node must become the root node.If the value is\
 * already present in the tree, it must be ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *curr = NULL;

	if (tree == NULL)
		return (NULL);
	new_node = (bst_t *)malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	curr = *tree;
	while (curr)
	{
		if (value > curr->n && curr->right == NULL)
		{
			curr->right = new_node;
			new_node->parent = curr;
			return (new_node);
		}
		else if (value < curr->n && curr->left == NULL)
		{
			curr->left = new_node;
			new_node->parent = curr;
			return (new_node);
		}
		else if (curr->n == value)
		{
			free(new_node);
			return (NULL);
		}
		else if (value > curr->n)
			curr = curr->right;
		else if (value < curr->n)
			curr = curr->left;
	}
	return (NULL);
}
