#include "binary_trees.h"
/**
 * is_valid_bst - checks if a subtree is a valid bst with\
 * with respect to parent tree.
 * @tree: subtree.
 * @parent: parent of the subtree to be compared.
 * @direction: for knowing if the subtree is a left or right child of tree.
 * Return: 1 if subtree satisfied conditions for binary search tree else 0.
 */
int is_valid_bst(const binary_tree_t *tree,
		const binary_tree_t *parent, int direction)
{
	const binary_tree_t **queue = NULL, *curr =  NULL;
	int front = 0, back = 0;

	queue = malloc(sizeof(binary_tree_t *) * 100);
	if (tree == NULL)
		return (1);
	if (queue == NULL)
	{
		return (0);
	}
	queue[back++] = tree;
	while (front < back)
	{
		curr = queue[front++];
		if (curr->n >= parent->n && direction == 1)
		{
			free(queue);
			return (0);
		}
		if (curr->n < parent->n && direction  == 2)
		{
			free(queue);
			return (0);
		}
		if (curr->left)
			queue[back++] = curr->left;
		if (curr->right)
			queue[back++] = curr->right;
	}
	free(queue);
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary_tree is a valid\
 * binary search Tree.
 * @tree: pointer to the root tree of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int valid = 0;

	if (tree == NULL)
	{
		return (0);
	}
	valid = is_valid_bst(tree->left, tree, 1)
		&& is_valid_bst(tree->right, tree, 2);
	if (valid)
	{
		if (tree->left && tree->right)
			return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
		else if (tree->right)
			return (binary_tree_is_bst(tree->right));
		else if (tree->left)
			return (binary_tree_is_bst(tree->left));
		else
			return (1);
	}
	return (0);
}
