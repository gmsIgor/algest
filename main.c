#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main(int argc, char **argv)
{
    int data[] = {2, 3, 9, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 5, 50};
    int dataLength = sizeof(data) / sizeof(data[0]);
    List *list1;
    list1 = createNPopulateList(data, dataLength);

    printList(list1);
    printf("2nd element is: %d\n", getElement(list1, 2)->data);
    printf("List length: %d\n", count(list1));
    pop(list1, 3);
    printList(list1);
    printf("List length: %d\n", count(list1));
    pushFront(list1, 678);
    printList(list1);
    printf("List length: %d\n", count(list1));
    push(list1, 5, 5323);
    printList(list1);
    printf("List length: %d\n", count(list1));
    clear(list1);
    printList(list1);
    printf("List length: %d\n", count(list1));
    return 1;
}
