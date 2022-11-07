#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

Node *getFirstElmnt(List *lst)
{
    return lst->list;
}

Node *getLastElmnt(List *lst)
{
    return lst->lastElmnt;
}

List *createNPopulateList(int data[], int dataLength)
{
    List *lst;
    lst = malloc(sizeof(List));
    lst->counter = 0;
    lst->list = NULL;
    lst->lastElmnt = NULL;

    int i;
    for (i = 0; i < dataLength; i++)
    {
        addElmntToList(lst, data[i]);
    }

    return lst;
}

void addElmntToList(List *lst, int data)
{
    Node *Elmnt;
    Elmnt = malloc(sizeof(Node));

    if (lst->list == NULL)
    {
        lst->list = Elmnt;
    }

    if (lst->lastElmnt != NULL)
    {
        lst->lastElmnt->next = Elmnt;
    }

    Elmnt->previous = lst->lastElmnt;
    lst->lastElmnt = Elmnt;
    Elmnt->data = data;
    Elmnt->next = NULL;
    lst->counter++;
}

void printList(List *lst)
{
    int i;
    Node *currentElmnt = lst->list;

    for (i = 0; i < lst->counter; i++)
    {
        if (currentElmnt == lst->lastElmnt)
        {
            printf("%d.\n", currentElmnt->data);
        }
        else
        {
            printf("%d, ", currentElmnt->data);
        }
        currentElmnt = currentElmnt->next;
    }
}

Node *getElement(List *lst, int n)
{
    if (lst->counter < n)
    {
        return NULL;
    }

    int step = 1;

    Node *currentElmnt = lst->list;
    int i = 1;
    if (lst->counter - n <= n - 1)
    {
        i = lst->counter;
        currentElmnt = lst->lastElmnt;
        step = -1;
    }

    while (i != n)
    {
        if (step > 0)
        {
            currentElmnt = currentElmnt->next;
        }
        else
        {
            currentElmnt = currentElmnt->previous;
        }
        i += step;
    }
    return currentElmnt;
}

int getListLength(List *lst)
{
    return lst->counter;
}

void removeElmnt(List *lst, int n)
{
    Node *elmnt = getElement(lst, n);
    if (elmnt == NULL)
    {
        return;
    }

    if (elmnt->previous != NULL)
    {
        elmnt->previous->next = elmnt->next;
    }
    else
    {
        lst->list = elmnt->next;
    }

    if (elmnt->next != NULL)
    {
        elmnt->next->previous = elmnt->previous;
    }
    else
    {
        lst->lastElmnt = elmnt->previous;
    }

    lst->counter -= 1;
    free(elmnt);
}