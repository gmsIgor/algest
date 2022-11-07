#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main(int argc, char **argv)
{
    int data[] = {2, 3, 9, 5, 50};
    int dataLength = sizeof(data) / sizeof(data[0]);
    List *list1;
    list1 = createNPopulateList(data, dataLength);

    printList(list1);
    printf("2nd element is: %d\n", getElement(list1, 2)->data);
    printf("List length: %d\n", getListLength(list1));
    removeElmnt(list1, 3);
    printList(list1);
    printf("List length: %d\n", getListLength(list1));

    return 1;
}
