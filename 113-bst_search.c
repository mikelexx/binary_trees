#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree.
 * @tree:  pointer to the root node of the BST to search.
 * @value:  the value to search in the tree.
 * Return: pointer to the node containing a value equals to value else NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *curr = tree;

	if (tree == NULL)
		return (NULL);
	while (curr)
	{
		if (curr->n == value)
		{
			return ((bst_t *)(curr));
		}
		if (value > curr->n && curr->right)
			curr = curr->right;
		else if (value < curr->n && curr->left)
			curr = curr->left;
		else
			return (NULL);
	}
	return (NULL);
}
