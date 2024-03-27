#include "binary_trees.h"
/**
 * replace_with_inorder_successor - replaces a pointer to  node with\
 * its inorder successor node.
 * @node: pointer to the node to be replace in the binary tree.
 * @curr: pointer to inorder successor of the node to be replaced.
 * @root: pointer to the root of binary tree containing the\
 * node to be replaced.
 * Return: root node of the new tree that has the curr node replaced.
 */
bst_t *replace_with_inorder_successor(bst_t *curr, bst_t *node, bst_t *root)
{
	if (curr->parent && curr->parent->left == curr)
		curr->parent->left = NULL;
	else if (curr && curr->parent)
		curr->parent->right = NULL;
	if (node->parent && node->parent->left == node)
	{
		node->parent->left = curr;
		curr->parent = node->parent;
	}
	else if (node->parent)
	{
		node->parent->right = curr;
		curr->parent = node->parent;
	}
	curr->left = node->left;
	if (node->left)
		node->left->parent = curr;
	node->left = NULL;
	if (curr->right != node->right)
	{
		curr->right = node->right;
		if (node->right)
			node->right->parent = curr;
		node->right = NULL;
	}
	if (node->parent == NULL)
		root = curr;
	return (root);
}
/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root:  pointer to the root node of the tree where you will remove a node.
 * @value: value to remove in the tree.
 * Description: Once located, the node containing a value equals\
 * to value must be removed and freed.If the node to be deleted\
 * has two children, it must be replaced with its first in-order\
 * successor (not predecessor).
 * Return: pointer to the new root node of the tree after removing the \
 * desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *curr = NULL;

	if (root == NULL)
		return (NULL);
	node = bst_search(root, value);
	if (node == NULL)
		return (NULL);
	curr = node->right;
	while (curr)
	{
		if (curr->left == NULL)
			break;
		curr = curr->left;
	}
	if (curr)
	{
		root = replace_with_inorder_successor(curr, node, root);
		free(node);
	}
	else if (node->parent && node->parent->right == node)
	{
		node->parent->right = node->left;
		node->left->parent = node->parent;
		node->parent = NULL;
		node->left = NULL;
		free(node);
	}
	else if (node->parent)
	{
		node->parent->left = node->left;
		node->left->parent = node->parent;
		node->parent = NULL;
		node->left = NULL;
		free(node);
	}
	else
	{
		root = node->left;
		root->parent = NULL;
		node->left = NULL;
		free(node);
		free(curr);
	}
	return (root);
}
