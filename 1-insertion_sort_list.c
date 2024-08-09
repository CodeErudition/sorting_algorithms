#include "sort.h"

/**
 * node_swapper - A function that swaps two adjacent nodes
 * in a doubly linked list.
 *
 * @list: Pointer to the head of the list.
 * @left: The left node to be swapped.
 * @right: The right node to be swapped.
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
 * insertion_sort_list - A function that sorts a doubly linked
 * list using insertion sort.
 *
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i_current, *i_temp;

	if (!list || !*list)
		return;

	i_current = (*list)->next;
	while (i_current)
	{
		while (i_current->prev && i_current->n < i_current->prev->n)
		{
			i_temp = i_current->prev;
			node_swapper(list, i_temp, i_current);
			print_list(*list);
		}
		i_current = i_current->next;
	}
}
