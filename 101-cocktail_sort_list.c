#include "sort.h"


void sw_n_a(listint_t **list, listint_t **tl, listint_t **shr)
{
    listint_t *tmp = (*shr)->next;

    if ((*shr)->prev)
        (*shr)->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = (*shr)->prev;
    (*shr)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *shr;
    else
        *tl = *shr;
    (*shr)->prev = tmp;
    tmp->next = *shr;
    *shr = tmp;
}

void sw_n_b(listint_t **list, listint_t **tl, listint_t **shr)
{
    listint_t *tmp = (*shr)->prev;

    if ((*shr)->next != NULL)
        (*shr)->next->prev = tmp;
    else
        *tl = tmp;
    tmp->next = (*shr)->next;
    (*shr)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *shr;
    else
        *list = *shr;
    (*shr)->next = tmp;
    tmp->prev = *shr;
    *shr = tmp;
}

void cocktail_sort_list(listint_t **list)
{
    listint_t *tl, *shr;
    int s = 0;
    int not_s = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    tl = *list;
    while (tl->next != NULL)
        tl = tl->next;

    while (s != not_s)
    {
        s = not_s;
        shr = *list;

        while (shr != tl)
        {
            if (shr->n > shr->next->n)
            {
                sw_n_a(list, &tl, &shr);
                print_list((const listint_t *)*list);
                s = 0;
            }
            else
            {
                shr = shr->next;
            }
        }

        if (s)
            break;

        s = not_s;
        tl = tl->prev;
        shr = tl;

        while (shr != *list)
        {
            if (shr->n < shr->prev->n)
            {
                sw_n_b(list, &tl, &shr);
                print_list((const listint_t *)*list);
                s = 0;
            }
            else
            {
                shr = shr->prev;
            }
        }
    }
}