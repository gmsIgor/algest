#include <stdio.h>
#include <stdlib.h>

#include "DoublyLinkedList.h"

int main(int argc, char **argv)
{
    int data[] = {2, 3, 9, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 5, 50};
    int dataLength = sizeof(data) / sizeof(data[0]);
    List *list1;
    list1 = Lkd_CreateNPopulateList(data, dataLength);

    Lkd_PrintList(list1);
    printf("2nd element is: %d\n", Lkd_GetElement(list1, 2)->data);
    printf("List length: %d\n", Lkd_Count(list1));
    Lkd_Pop(list1, 3);
    Lkd_PrintList(list1);
    printf("List length: %d\n", Lkd_Count(list1));
    Lkd_PushFront(list1, 678);
    Lkd_PrintList(list1);
    printf("List length: %d\n", Lkd_Count(list1));
    Lkd_Push(list1, 5, 5323);
    Lkd_PrintList(list1);
    printf("List length: %d\n", Lkd_Count(list1));
    Lkd_Clear(list1);
    Lkd_PrintList(list1);
    printf("List length: %d\n", Lkd_Count(list1));
    return 1;
}
