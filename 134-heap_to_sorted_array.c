#include "binary_trees.h"

/**
 * heapify_down - Restores the Max Heap property by moving the root down
 * @root: Pointer to the root node of the Heap
 */
void heapify_down(heap_t *root)
{
	heap_t *current = root, *max_child = NULL;
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
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t i = 0;
	heap_t *last_node;

	if (!heap)
		return (NULL);

	*size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * (*size));
	if (!sorted_array)
		return (NULL);

	while (heap)
	{
		sorted_array[i++] = heap->n;
		last_node = get_last_node(heap);
		if (heap == last_node)
			break;
		heap->n = last_node->n;
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
		free(last_node);
		heapify_down(heap);
	}

	return (sorted_array);
}

