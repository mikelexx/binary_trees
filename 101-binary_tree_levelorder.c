#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree using level-order\
 * traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The\
 * value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue  = malloc(sizeof(binary_tree_t *) * 100);
	const binary_tree_t *curr = NULL;
	int front = 0, back = 0;

	queue[back] = tree;
	back++;
	while (front < back)
	{
		curr = queue[front];
		func(curr->n);
		if (curr->left)
			queue[back++] = curr->left;
		if (curr->right)
			queue[back++] = curr->right;
		front++;
	}
	free(queue);
}

