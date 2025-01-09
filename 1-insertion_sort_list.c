#include "sort.h"

/**
 * swap_nodes - Swaps nodes in a doubly linked list.
 *
 * @list: A pointer to the head of the list.
 * @node_a: A pointer to the first node to swap.
 * @node_b: A pointer to the sxond node to swap.
 *
 * Return: nothing.
 */

void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	/*if 1st node exists, make next ptr 2nd node */
	if (node_a->prev != NULL)
		node_a->prev->next = node_b;

	/*If its the head, update to 2nd node*/
	else
		*list = node_b;
	/*make sure 2nd node is not the tail, make prev ptr the 1st node*/
	if (node_b->next != NULL)
		node_b->next->prev = node_a;

	/*Update pointers*/
	node_b->prev = node_a->prev;
	node_a->next = node_b->next;
	node_b->next = node_a;
	node_a->prev = node_b;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using th Insertion sort algorithm.
 * @list: A double pointer to a list of integers.
 *
 * Return: nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	/*Check if list is  empty, or only 1 node*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/**start soirting with 2nd node*/
	current = (*list)->next;

	/*Iterate list from second*/
	while (current != NULL)
	{
		prev = current->prev;

		/*Check is current node is < prev*/
		while (prev != NULL && current->n < prev->n)
		{
			/*if smaller, swap and move to 'sorted'*/
			swap_nodes(list, prev, current);
			print_list(*list);
			/*update after swapping*/
			prev = current->prev;
		}
		/*Move to next node*/
		current = current->next;
	}
}
