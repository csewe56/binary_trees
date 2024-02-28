#include "binary_trees.h"

/**
 * heapify_down - Restores the Max Heap property by moving the new root down
 * @root: Pointer to the root node of the Heap
 */
void heapify_down(heap_t **root)
{
	heap_t *current = *root, *max_child = NULL;
	int temp;

	while (current)
	{
		max_child = current->left;

		if (current->right && current->right->n > max_child->n)
			max_child = current->right;

		if (!max_child)
			break;

		if (max_child->n > current->n)
		{
			temp = current->n;
			current->n = max_child->n;
			max_child->n = temp;
			current = max_child;
		}
		else
			break;
	}
}

/**
 * get_last_node - Gets the last node in the heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (!root)
		return (NULL);

	while (root->left || root->right)
	{
		if (root->right)
			root = root->right;
		else
			root = root->left;
	}

		return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	parent = last_node->parent;

	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	last_node->parent = NULL;
	last_node->left = (*root)->left;
	last_node->right = (*root)->right;

	if ((*root)->left)
		(*root)->left->parent = last_node;
	if ((*root)->right)
		(*root)->right->parent = last_node;

	free(*root);
		*root = last_node;

	heapify_down(root);

	return (value);
}

