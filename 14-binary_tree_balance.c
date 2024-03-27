#include "binary_trees.h"
/**
 * get_binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the tree node of the tree to measure the height.
 * Return: height of tree, else 0 if tree is NULL.
 */
int get_binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = 1 + get_binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + get_binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
/**
 * binary_tree_balance - the balance factor of a binary tree.
 * @tree: pointer to the tree node of the tree to measure\
 * the balance factor.
 * Return: If tree is NULL, return 0 else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_subtree_height = 0, right_subtree_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right == NULL)
		return (get_binary_tree_height(tree->left) + 1);
	if (tree->right && tree->left == NULL)
		return (-1 - get_binary_tree_height(tree->right));
	if (tree->right == NULL && tree->left == NULL)
		return (0);
	left_subtree_height = get_binary_tree_height(tree->left);
	right_subtree_height = get_binary_tree_height(tree->right);
	return (left_subtree_height - right_subtree_height);
}
