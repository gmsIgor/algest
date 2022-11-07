
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

// Add a new element to the list.
void addElmntToList(List *lst, int data);

// Return the first element of the list.
Node *getFirstElmnt(List *lst);

// Return the last element of the list.
Node *getLastElmnt(List *lst);

// Return the element in position n of the sequence in the list
// or NULL if there isn't an element in position n.
Node *getElement(List *lst, int n);

// Return the amount of elements in the list.
int getListLength(List *lst);

// Remove element in position n in the list if it exists.
void removeElmnt(List *lst, int n);