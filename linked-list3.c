// a simple C program to introduce a linked list
// a linked list

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int data;  //use int as an example
    struct Node* next_node;
};

    
// This function prints contents of linked list starting from head
/* 
    In the previous program, we've created a simple linked list with three nodes. 
    Let us traverse the created list and print the data of each node. For traversal,
    let us write a general-purpose function printList() that prints any given list
*/

void printNodeList (struct Node* n) {
    printf("[");
    while (n) {  
        assert (n != NULL);
        printf(" %d ", n -> data); 
        n = n -> next_node; 
    } 
    printf("]");
}

//print list in reverse
void printReverseList (struct Node* head) {  
    if (head == NULL) return;
     
    printReverseList(head -> next_node);  
    printf(" %d ", head -> data);     
}


//this function will allow us to insert a node at the front
/*
    Node can be added in 3 ways:
    - At front of linked list
    - After given node
    - At end of linked list

    Example:
    - The new node is always added before the head of the given linked list.
      And newly added node becomes the new head of the linked list.

    [ 10 -> 15 -> 20 -> 25] , and we add an item 5 at the front

    [ 5 -> 10 -> 15 -> 20 -> 25]

    - Function that adds at front of list is called push() which must
      receive a pointer to the head pointer, because push must change
      the head pointer to point to the new node
*/


/* Given reference (pointer to pointer) to head of list and an int, 
   inserts new node on the front of the list */
void pushNode (struct Node** head_ref, int new_data) {
    /* 1. Allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. Put in data */
    new_node -> data = new_data;

    /* 3. Make next of new data as head */
    new_node -> next_node = (*head_ref);

    /* 4. Move head to point to new node */
    (*head_ref) = new_node;
}
//time complexity of push() is O(1) as it does work at constant time


//function for adding node after a given node
/* Given a node prev_node, insert a new node after given prev_node*/
void insertNodeAfter (struct Node* prev_node, int new_data) {
    /* 1. Check if given prev_node is NULL */
    if (prev_node == NULL) {
        printf("The given previous node cannot be null!");
        return;
    }

    /* 2. Allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    /* 3. Put in data */
    new_node -> data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node -> next_node = prev_node -> next_node;

    /* 5. Move next of prev_node as new_node */
    prev_node -> next_node = new_node;
}
//time complexity of insertAfter() is O(1) as it does work at constant time


//Function to add node to the end of the linked list
/* 
    - The new node is always added after the last node of the given linked list. 
    For example,

    if [5 -> 10 -> 15 -> 20 -> 25] , and we add an item 30 at end

    [5 -> 10 -> 15 -> 20 -> 25 -> 30]

    - Since the linked list is typically represented by the head of it, we have 
      to traverse the list until the very end then change next of last node to new node.
*/

/* Given reference (pointer to pointer) to the head of list and an int, 
   this function appends a new node at the very end of a linked list*/
void appendNode (struct Node** head_ref, int new_data) {
    /*1. Allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5 */

    /* 2. Put in the data */
    new_node -> data = new_data;

    /* 3. This new node is going to be the last node , so make next of it as NULL */
    new_node -> next_node = NULL;

    /* 4. If linked list empty, then make the new node as head*/
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse until the very last node*/
    while (last -> next_node != NULL) {
        last = last -> next_node;
    }

    /* 6. Change next of last node */
    last -> next_node = new_node;
    return;

    /*
        - Time complexity of append() is O(n) where n is number of nodes in linked list
        - Since there is a loop from head to end, the function does work in O(n) linear time
        - However, the method can be optimized to work in O(1) constant time by 
          keeping an extra pointer to the the tail (very end) of the linked list 
    */
}

//To delete a node from the linked list, we needed to do the following steps:
/* 
    1) Find previous node of the node to be deleted
    2) Change next of previous node
    3) Free memory for the node to be deleted
*/

// Since every node of the linked list is dynamically allocated using malloc() in C,
// we need to call free() for freeing memory allocated for the node to be deleted

/* Given a reference (pointer to pointer) to the head of a list and key, deletes
   first occurence of the node in the singly linked list */

void deleteNodeAtOccurence (struct Node** head_ref, int key) {
    // Store head node
    struct Node *temp = *head_ref, *prev_node;

    //if head node itself holds the key to be deleted
    if (temp != NULL && temp -> data == key) {
        *head_ref = temp -> next_node; //changed head
        free(temp); // free old head
        return;
    } else {
        printf("That's not a value in the linked list!");
        return;
    }

    //search for key to be deleted, keep track
    // of the previous node as we need to change "prev_node -> next_node"
    while (temp != NULL && temp -> data != key) {
        prev_node = temp;
        temp = temp -> next_node;
    }

    //if key was not present in linked list 
    if (temp == NULL) return;

    //unlink the node from linked list
    prev_node -> next_node = temp -> next_node;

    free(temp); //free memory

    /*
        - Time complexity of deleteNode() is O(n) where n is number of nodes in linked list
        - Since there is a loop from head to end, the function does work in O(n) linear time
        - However, the method can be optimized to work in O(1) constant time by 
          keeping an extra pointer to the the tail (very end) of the linked list 
    */
}

// Function to delete a linked list node at a given position
void deleteNodeAtPosition (struct Node **head_ref, int position) {
    // if linked list is empty
    if (*head_ref == NULL) return;

    //store head node
    struct Node* temp = *head_ref;

    //if head needs to be removed
    if (position == 0) {
        *head_ref = temp -> next_node; //change head
        free(temp); //free old head
        return;
    } else {
        printf("That's not an index in the linked list!");
        return;
    }

    //find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp -> next_node;
    }

    //if position is more than number of nodes
    if (temp == NULL || temp -> next_node) return;

    //node temp -> next_node is the node to be deleted
    //store pointer to the next of node to be deleted
    struct Node *next_node = temp -> next_node -> next_node;

    //unlink the node from linked list
    free (temp -> next_node); //unlink deleted node from list

    //unlink deleted node from list
    temp -> next_node -> next_node;
}

// function to count the number of nodes in a given singly linked list

/* ITERATIVE SOLUTION:
    1) Initialize count as 0
    2) Initialize node pointer, current = head
    3) Do followng while current is not NULL
        a) current = current -> next_node
        b) count++;
    4) Return count
*/

/* Iteratively counts number of nodes in the singly linked list*/
int getNodeCountIteratively (struct Node* head) {
    int count = 0; //initialize count
    struct Node* current = head; //initialize current 
    while (current != NULL) {
        count++;
        current = current -> next_node;
    }

    return count;
}

/* RECURSIVE SOLUTION:
    1) If head is NULL, return 0.
    2) Else, return 1 + getNodeCountRecursively (head -> next_node)
*/

/* Recursively count number of nodes in the singly linked list*/
int getNodeCountRecursively (struct Node* head) {
    //base case
    if (head == NULL) return 0;

    //count is count + 1 count of remaining list
    return 1 + getNodeCountRecursively (head -> next_node);
} 

// Program to create a simple linked list with just 3 nodes + additional functions :)
int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //allocate 3 nodes in the heap
    head  = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    /* 
        Three blocks have been allocated dynamically. We
        have pointers to these three blocks as head, 2nd, and 3rd

               head           second           third 
                |                |               | 
                |                |               | 
            +---+-----+     +----+----+     +----+----+ 
            | #  | #  |     | #  | #  |     |  # |  # | 
            +---+-----+     +----+----+     +----+----+ 
            
        /* # represents any random value. 
        Data is random because we haven’t assigned  
        anything yet  */

        head -> data = 1; //assign data in first node
        head -> next_node = second; //link first node with the second node

        /* data has been assigned to the data part of the first 
           block (block pointed by the head). And next pointer of 
           first block points to the second one. So they're both linked.

                  head          second         third 
                    |              |              | 
                    |              |              | 
                +---+---+     +----+----+     +-----+----+ 
                | 1  | o----->| #  | #  |     |  #  | #  | 
                +---+---+     +----+----+     +-----+----+
        */

        second -> data = 2; //assign data to 2nd node
        
        second -> next_node = third; //link second node to 3rd node

        /* data has been assigned to the data part of the 
           second block (blocked pointed by second node).
           And next pointer of the second block points to 
           the third block. So all three blocks are now linked.

                  head         second         third 
                    |             |             | 
                    |             |             | 
                +---+---+     +---+---+     +----+----+ 
                | 1  | o----->| 2 | o-----> |  # |  # | 
                +---+---+     +---+---+     +----+----+ 
        */

        third -> data = 3; //assign data to third node
        third -> next_node = NULL;

        /* data has been assigned to data part of third
           block (block pointed by 3rd block). And next
           pointer of the 3rd block is made NULL to indicate
           that the linked list is terminated here.

           We have the linked list ready.

            head     
             | 
             |  
        +---+---+     +---+---+       +----+------+ 
        | 1  | o----->|  2  | o-----> |  3 | NULL | 
        +---+---+     +---+---+       +----+------+  

        Note that the only head is sufficient to represent
        the whole list . We can traverse the complete list
        by following the next pointers.
        */

        //insert 6 so linked list could become [6, 1, 2, 3, NULL]
        pushNode(&head, 6);

        //insert 7 so linked list could become [7, 6, 1, 2, 3, NULL]
        pushNode(&head, 7);

        //insert 1 so linked list could become [1, 7, 6, 1, 2, 3, NULL]
        pushNode(&head, 1);

        //insert 4 at the end so linked list could become [1, 7, 6, 1, 2, 3, 4, NULL]
        appendNode(&head, 4);

        // Insert 8, after 7. So linked list could become [1, 7, 8, 6, 1, 2, 3, 4, NULL]
        insertNodeAfter(head -> next_node, 8); 

        //delete 1 , so linked list could become [7, 8, 6, 1, 2, 3, 4, NULL]
        //only deletes the first occurrence of number 1, so the second 1 remains
        //if user puts in a number not in linked list, computer will output "That's not a value in the linked list!"
        deleteNodeAtOccurence(&head, 1); 

        pushNode(&head, 6); // [6, 7, 8, 6, 1, 2, 3, 4, NULL]

        //will remove the 6 at index 0
        //if user puts in an index not in linked list, computer will output "That's not an index in the linked list!"
        deleteNodeAtPosition(&head, 0); 

        printf("\nCreated Linked list is: "); // [7, 8, 6, 1, 2, 3, 4 , NULL]
        printNodeList(head); 

        printf("\nReverse Linked list is: "); // [4, 3, 2, 1, 6, 7, 8, NULL]
        printf("[");
        printReverseList(head);
        printf("]");

        /*
            1) The iteration is when a loop repeatedly executes until the controlling condition becomes false
            2) The recursion is when a statement in a function calls itself repeatedly. 
        */
        
        printf("\nIterative node count is: %d\nRecursive node count is: %d", getNodeCountIteratively(head), getNodeCountRecursively(head)); 

        return 0;
} 