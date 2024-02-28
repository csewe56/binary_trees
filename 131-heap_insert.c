#include "binary_trees.h"

/**
 * find_parent - Finds the parent node for insertion
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent = NULL;

	while (root)
	{
		parent = root;
		root = root->left;
	}

	return (parent);
}

/**
 * heapify_up - Restores the Max Heap property by moving the new node up
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	parent = find_parent(*root);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	heapify_up(new_node);

	return (new_node);
}

