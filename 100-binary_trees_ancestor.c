#include "binary_trees.h"
const binary_tree_t *find_descedant(const binary_tree_t *first,
		const binary_tree_t *second, int direction)
{
	const binary_tree_t *left_descedant = NULL, *right_descedant = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->left == second || first->right == second)
		return (first);
	if (direction == 1)
	{
		left_descedant = find_descedant(first->left, second, 3);
		if (left_descedant)
			return (first);
	}

	else if (direction == 2)
	{
		left_descedant = find_descedant(first->right, second, 3);
		if (left_descedant)
			return (first);
	}
	else if (direction  == 3)
	{
		left_descedant = find_descedant(first->left, second, 3);
		right_descedant = find_descedant(first->right, second, 3);
		if (left_descedant || right_descedant)
			return (first);
		else
			return (NULL);
	}
	return (NULL);

}
/**
 * binary_trees_ancestor - lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return: pointer to the lowest common ancestor node of the two given nodes\
 * or if no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *desc = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	desc = find_descedant(first, second, 3);
	if (desc == first)
		return ((binary_tree_t *)(desc));
	while (first->parent != NULL)
	{
		if (first->parent->right == first)
		{
			if (find_descedant(first->parent, second, 1))
				return (first->parent);
		}
		if (first->parent->left == first)
		{
			if (find_descedant(first->parent, second, 2))
				return (first->parent);
		}
		first = first->parent;
	}
	return (NULL);
}
