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
    lst = (List *)malloc(sizeof(List));
    lst->counter = 0;
    lst->list = NULL;
    lst->lastElmnt = NULL;

    int i;
    for (i = 0; i < dataLength; i++)
    {
        pushBack(lst, data[i]);
    }

    return lst;
}

void pushBack(List *lst, int data)
{
    Node *Elmnt;
    Elmnt = (Node *)malloc(sizeof(Node));

    if (lst->list == NULL)
    {
        lst->list = Elmnt;
    }

    if (lst->lastElmnt != NULL)
    {
        lst->lastElmnt->next = Elmnt;
    }

    Elmnt->previous = lst->lastElmnt;
    Elmnt->data = data;
    Elmnt->next = NULL;
    lst->lastElmnt = Elmnt;
    lst->counter++;
}

void pushFront(List *lst, int data)
{
    Node *Elmnt;
    Elmnt = (Node *)malloc(sizeof(Node));

    if (lst->lastElmnt == NULL)
    {
        lst->lastElmnt = Elmnt;
    }

    if (lst->list != NULL)
    {
        lst->list->previous = Elmnt;
    }

    Elmnt->next = lst->list;
    Elmnt->previous = NULL;
    Elmnt->data = data;
    lst->list = Elmnt;
    lst->counter++;
}

void push(List *lst, int n, int data)
{
    Node *currentN = getElement(lst, n);

    if (currentN == NULL)
    {
        pushBack(lst, data);
        return;
    }

    Node *newElmnt = (Node *)malloc(sizeof(Node));

    newElmnt->previous = currentN->previous;
    newElmnt->next = currentN;
    currentN->previous->next = newElmnt;
    currentN->previous = newElmnt;
    newElmnt->data = data;
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

int count(List *lst)
{
    return lst->counter;
}

void pop(List *lst, int n)
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

void popBack(List *lst)
{
    Node *elmnt = lst->lastElmnt;
    if (elmnt == NULL)
    {
        return;
    }

    if (lst->counter > 1)
    {
        elmnt->previous->next = NULL;
        lst->lastElmnt = elmnt->previous;
    }
    else
    {
        lst->lastElmnt = NULL;
        lst->list = NULL;
    }

    lst->counter -= 1;
    free(elmnt);
}

void popFront(List *lst)
{
    Node *elmnt = lst->list;
    if (elmnt == NULL)
    {
        return;
    }

    if (lst->counter > 1)
    {
        elmnt->next->previous = NULL;
        lst->list = elmnt->next;
    }
    else
    {
        lst->lastElmnt = NULL;
        lst->list = NULL;
    }

    lst->counter -= 1;
    free(elmnt);
}

void clear(List *lst)
{
    int i = lst->counter;

    while (i > 0)
    {
        popFront(lst);
        i--;
    }
}