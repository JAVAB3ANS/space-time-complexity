//Intro to Linked Lists (in C)

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data; //use int as an example
  struct Node* next; 
} Node;

Node* node_constructor(int data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  return new_node;
}

Node* node_append(Node* base, int data) {
  base->next = node_constructor(data);
  return base->next;
}

void node_free(Node* base) {
  if (base->next != NULL) node_free(base->next);
  free(base);
}

void node_print(Node* base) {
  printf("[");
  while(base->next != NULL) {
    printf("%d, ", base->data);
    base = base->next;
  }
  if (base) printf("%d", base->data);
  printf("]");
}

int main() {
  Node* first = node_constructor(1);
  Node* tracker = first;
  tracker = node_append(tracker, 2);
  tracker = node_append(tracker, 3);
  node_print(first);
  node_free(first);
}