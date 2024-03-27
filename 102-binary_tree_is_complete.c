#include "binary_trees.h"
/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL or not complete, else 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 100);
	const binary_tree_t *curr = NULL;
	if (queue == NULL)
		return (0);
	int front = 0, back = 0;
	queue[back++] = tree;
	while (front < back)
	{
		curr = queue[front++];
		if (curr != NULL)
		{
			queue[back++] = curr->left;
			queue[back++] = curr->right;
		}
		else
		{
			while (front < back)
			{
				if (queue[front++] != NULL)
				{
					free(queue);
					return (0);
				}
			}
			free(queue);
			return (1);
		}
	}
	free(queue);
	return (1);
}
