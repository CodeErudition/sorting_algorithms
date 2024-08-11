#include "sort.h"

/**
 * node_swapper - A function that swap two adjacent nodes in
 * a doubly linked list.
 *
 * @list: Double pointer to the head of the list.
 * @left: Pointer to the left node.
 * @right: Pointer to the right node.
 */

void node_swapper(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - A function that sorts a doubly
 * linked list of integers in ascending
 *
 * order using the Cocktail Shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *c_current;
	int c_swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		c_swapped = 0;
		c_current = *list;

		while (c_current->next)
		{
			if (c_current->n > c_current->next->n)
			{
				node_swapper(list, c_current, c_current->next);
				print_list(*list);
				c_swapped = 1;
			}
			else
				c_current = c_current->next;
		}

		if (!c_swapped)
			break;

		c_swapped = 0;

		while (c_current->prev)
		{
			if (c_current->n < c_current->prev->n)
			{
				node_swapper(list, c_current->prev, c_current);
				print_list(*list);
				c_swapped = 1;
			}
			else
				c_current = c_current->prev;
		}
	} while (c_swapped);
}
