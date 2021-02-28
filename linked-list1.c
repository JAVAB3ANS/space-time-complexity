#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

struct node {
    int data; // use int as an example
    struct node *next;
};

struct list {
    int count;
    struct node *head;
};

//Create a list

struct list *CreateList() {
    struct list *pList; //pointer named pList 
    pList = malloc(sizeof(struct list)); //then allocate (malloc) memory for the pointer
    assert(pList != NULL); //use assert to see if the pList pointer is null or not 

    pList -> count = 0; //assign pList to count and initialize it to 0 because on start, list is empty
    pList -> head = NULL; //assign pList to head and initialize it to NULL

    return pList; 
};

//Insert a node

void insert (struct list *pList, struct node *pPrev, struct node *pNew) {
    //pPrev = NULL if inserting as first node; this is the previous node
    //pNew = use pNew to link current node to the link list

    if (pPrev == NULL) { //if cases 3 and 4
        pNew -> next = pPrev -> next;
        pPrev -> next = pNew;
    }

    pList -> count++;
};

// Allocate memory for a new node
/* 
   We need to allocate memory every time when we generate a new node. 
   It's the same process. So we omit it in the later discussions.
*/

struct node *pNew;
pNew = malloc(sizeof(struct node));
assert(pNew != NULL);
pNew -> data = val;

// Link the node to the list
/* 
    - Assume we have already created a linked list and allocated memory for new ndoe.
    - To insert a new node, what do you need to know?
*/

/*
    ===DIFFERENT SITUATIONS===

    - Insert in midde:
        > Predecessor: (yes)
        > Successor: (yes)
    - Insert at end:
        > Predecessor: (yes)
        > Successor: (no) - points to null!
    - Insert into end:
        > Predecessor: (no) - points to null!
        > Sucessor: (no) - points to null!
    - Insert at beginning:
        > Predecessor: (no) - points to null!
        > Sucessor: (yes)
*/

// ===INSERT IN MIDDLE===
/*
    Now we have a list with several nodes, and we 
    want to add a new node in the middle of the list.
*/

pNew -> next = pPrev -> next;
pPrev -> next = pNew;
pList -> count++;

// ===INSERT AT END===
/* 
    - Now we have a list with several nodes, and we 
      want to add a new node at the end of the list.

    - First, new node is still connected with successor.
      Disconnect predecessor with the successor and create
      the connection with the new node.

    - Exact same operation as "insert new node in middle"
*/

//manipulate two pointers: pNew and pPrev
// 

pNew -> next = new;
pPrev -> next = pNew;
pList -> count++;

// ===INSERT AT BEGINNING===
/* 
    Now we have a list with one/several node(s), and we 
    want to add a new node at the beginning of the list
*/
// when you insert a new element in, you have to increase by one for pList -> count++


pNew -> next = pList -> head;
pList -> head = pNew;
pList -> count++;


// ===INSERT ELEMENT INTO EMPTY LIST===
/*
    An empty list has the list structure only.
*/

//order to connect new node to existing current list
pNew -> next = pPrev;
pList -> head = pNew -> data;

// === DELETING ITEMS ===


void delete(struct node *pList, struct node * pPrev) {
    //pPrev == NULL if you want to delete the first node
    assert (pList != NULL && pPrev != NULL); 
    pDel = pList -> next;
    pPrev -> next = pDel -> next;
    pList -> count--;
    free(pDel); 
}

/*
    - When given pPrev (the address of the previous node), it takes
      O(1) to insert/delete a node in a linked list.

    - Then how do we find pPrev.

    - If you don't have address of previous element, you need 
      sequential search throughout the entire list.

    - Check if pPrev is given, you just need to delete next element, therefore O(1).

    - Otherwise, it's O(n).
*/

// == Linked List - Search ==

/* 
    - To search a linked list, no matter it's ordered or not, we 
      have to do sequential search because there's no physical
      relationship among the nodes. 

    - Must follow linked-list sequence from first to last node in the linked list.
    
    - Big-O Notation: O(n)
*/

// Search - Exercise 1:
/* What is the Big-O runtime for the following tasks?

   > In an unsorted singly linked list
     - Find a specific value: O(n)
     - Find the largest value: O(n) -- you don't know largest element and where it 
            is stored; don't know address of largest element, so you have to search entire 
            linked list to compare nodes and find the largest element; linked list doesn't
            have the concept of the array no matter how large it is (fixed)
     - Find the smallest value: O(n) -- you don't know largest element and where it 
            is stored; don't know address of smallest element, so you have to search entire 
            linked list to compare nodes and find the smallest element
     - Remove the largest value: O(n) -- you don't know largest element and its address; need
            to go through entire list to remove it; finding successor and predecessor takes 
            O(n) and when added together, it's still O(n) -- [O(n) + O(n) + O(n) = O(n)]
     - Remove the smallest value: O(n) -- you don't know smallest element and its address; need
            to go through entire list to remove it; finding successor and predecessor takes 
            O(n) and when added together, it's still O(n) -- [O(n) + O(n) + O(n) = O(n)]
     - Insert new value at end of list: O(n) -- finding last element takes O(n)

    > How about an unsorted singly linked circular list?
        - Find a specific value: O(n)
        - Find the largest value: O(n)
        - Find the smallest value: O(n)
        - Remove the largest value: O(n) 
        - Remove the smallest value: O(n)
        - Insert new value at end of list: O(n) -- even if structure changes a bit, pointer still points 
          to first node; you still need to manipulate node to connect other nodes
*/

// Search - Exercise 2:
/* 
    > How about an sorted singly linked list?
        - Find a specific value: O(n) -- only can do sequential search to identify specific value
        - Find the largest value: O(n) -- it's ascending order which means largest element is stored at last node;
          find last node by going from "n" node to the last to find address; head pointer -> 1st node -> 2nd node -> "n.."
        - Find the smallest value:  O(1) -- first node has smallest value 
        - Remove the largest value: O(n) -- [O(n) * O(n)]
        - Remove the smallest value: O(1) -- [O(n) * O(1) = O(1)], where O(1) takes higher precedence
        - Insert new value at end of list: O(n) -- [O(n) * O(n)]
    
    > How about an sorted circular doubly linked list?
        - Find a specific value: O(n) -- because you use sequential search
        - Find the largest value: O(1) -- because you know the largest element is stored at the last node;
          from first node you can reach the last node, taking you one step
        - Find the smallest value: O(1) -- because smallest value is stored in the first node 
        - Remove the largest value: O(1) -- the largest value should be at the last node , then you 
          search for the last node -> using pPrev (reaching predecessor) only takes you O(1) steps;
          you were able to reach last element with O(1) and access predecessor with O(1)
        - Remove the smallest value: O(1) -- you can link head node with accessing the pointer so O(1) steps
        - Insert new value at end of list O(n) -- need to find correct location using sequential search;
          can't insert at first or last, you have to insert at the correct sorted index 

// Linked List - Search
/* 
    - Given a sorted singly linked list (ascending order) , what to return?
      > Found - true? Or false?
      > If the node is found in the list, return is location through "pLoc", or pointer of location
      > If the node isn't found, return the location where it should be placed, using "pLoc"
      > For insertion/deletion purposes, we also need to return the location of the previous node (i.e. pPrev)
*/

// CODE: Sorted Linked List Search

bool ListSearch(struct list *pList, struct node, **pPrev, struct node **pLoc, struct node *pTarget) {
    assert (pList != NULL && pTarget != NULL)
    *pPrev = NULL; //or dummy node, depending on how you create the linked list.
    *pLoc = pList -> head;
    while (*pLoc != NULL && pTarget -> data -> *pLoc -> data) {
        *pPrev = *pLoc;
        *pLoc = *pLoc -> next;
    }

    if (*pLoc == NULL) return false;
    if (pTarget -> data == *pLoc -> data) return true;
    return false;
}

/*
    Linked List with a Tail Pointer

    - Advantage: make it possible to directly access the last element in the list.
        e.g. 1. We want to add a new element at the end of the list.
             2. Access the min/max element if the linked list was sorted
        
    - Question: If we want to access the element right before the last element
      in the list, will the tail pointer make it easier?

    - Further question: How about if we want to remove the last element?

*/

// Search - Exercise 3:
/* 
    > How about an sorted singly linked list with a tail pointer (ascending order)?
        - Find a specific value: O(n) 
        - Find the largest value: O(1) -- greatest element should be the last element; tail pointer
          reaches last element with O(1) steps 
        - Remove the largest value: O(n)
        - Find the smallest value: O(1)
        - Remove the smallest value: O(1) 
        - Insert new value at end of list: O(n) -- you need to find correct location with sequential search to insert 
          (e.g. for example , you insert 10 and you need to connect with successor and change predecessor) 
*/

// NEXT CLASS: Linked-List Traversal and Binary Trees

/*
Why don't we need to free memory in the pop/dequeue operation?

- If we were to free memory within our code, it would potentially
  free the other values within our data set. This usually depends
  on how we declare our area. If each element is specialized to have
  its own memory block, that's fine but it can't do it with more 
  elements in the same memory.
*/