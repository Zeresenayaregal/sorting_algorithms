#include "sort.h"

/**
 * insertion_sort_list - perform insertion sort ( Linked_List )
 * @list: The head ( Starting ) node of Linked_List
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *swp, *prv;

	if (!list || !*list)
		return;

	crnt = *list;
	while ((crnt = crnt->next))
	{
		swp = crnt;
		while (swp->prev && swp->n < swp->prev->n)
		{
			prv = swp->prev;
			if (swp->next)
				swp->next->prev = prv;
			if (prv->prev)
				prv->prev->next = swp;
			else
				*list = swp;
			prv->next = swp->next;
			swp->prev = prv->prev;
			swp->next = prv;
			prv->prev = swp;

			print_list(*list);
		}
	}
}
