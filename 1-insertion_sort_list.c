#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *previous;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		previous = current->prev;

		while (previous != NULL && previous->n > current->n)
		{
			next = current->next;

			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*list = current;

			current->prev = previous->prev;
			current->next = previous;

			previous->prev = current;
			previous->next = next;

			if (next != NULL)
				next->prev = previous;

			print_list(*list);

			previous = current->prev;
		}

		current = current->next;
	}
}
