
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct List
{
    Node *list;
    Node *lastElmnt;
    int counter;
} List;

// Create a new list and populate with data from given int data array.
List *createNPopulateList(int data[], int dataLength);

// Print all elements in the list to stdout.
void printList(List *lst);

// Create and add a new element containing data at the end of the list.
void pushBack(List *lst, int data);

// Create and add a new element at the beginning of the list.
void pushFront(List *lst, int data);

// Create and add a new element at the n-th position of the list.
// If there isn't a n-th element, add element at the end.
void push(List *lst, int n, int data);

// Return the first element of the list.
Node *getFirstElmnt(List *lst);

// Return the last element of the list.
Node *getLastElmnt(List *lst);

// Return the element at the n-th position of the sequence in the list
// or NULL if there isn't a n-th element.
Node *getElement(List *lst, int n);

// Return the amount of elements in the list.
int count(List *lst);

// Remove element at the n-th position of the list if it exists.
void pop(List *lst, int n);

// If it exists, remove the last element from the list.
void popBack(List *lst);

// If it exists, remove the first element from the list.
void popFront(List *lst);

// If there is any, remove all the elements from the list.
void clear(List *lst);