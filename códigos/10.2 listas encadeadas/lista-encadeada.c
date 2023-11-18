#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *next;
  struct Node *prev;
} Node;

Node *nodeCreate(int key) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->key = key;
  node->next = node->prev = NULL;
  return node;
}

typedef struct {
  Node *head;
} List;

List *listCreate() {
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  return l;
}

Node *listSearch(List *l, int k) {
  Node *x = l->head;
  while (x != NULL && x->key != k) {
    x = x->next;
  }
  return x;
}

void listPrepend(List *l, Node *x) {
  x->next = l->head;
  x->prev = NULL;
  if (l->head != NULL) {
    l->head->prev = x;
  }
  l->head = x;
}

void listInsert(Node *x, Node *y) {
  x->next = y->next;
  x->prev = y;
  if (y->next != NULL) {
    y->next->prev = x;
  }
  y->next = x;
}

void listDelete(List *l, Node *x) {
  if (x->prev != NULL) {
    x->prev->next = x->next;
  } else {
    l->head = x->next;
  }
  if (x->next != NULL) {
    x->next->prev = x->prev;
  }
}

void listDestroy(List *l) {
  Node *x = l->head;
  while (x != NULL) {
    Node *aux = x;
    x = x->next;
    free(aux);
  }
  free(l);
}

int main() {
  Node *node1 = nodeCreate(10);
  Node *node2 = nodeCreate(20);
  Node *node3 = nodeCreate(30);

  List *myList = listCreate();
  listPrepend(myList, node1);
  listPrepend(myList, node2);
  listPrepend(myList, node3);

  printf("Original list:");
  for (Node *current = myList->head; current != NULL; current = current->next) {
    printf(" %d", current->key);
  }
  printf("\n");

  int key;
  printf("Enter search key: ");
  scanf("%d", &key);
  Node *searchResult = listSearch(myList, key);

  if (searchResult != NULL) {
    Node *node4 = nodeCreate(40);
    printf("Inserting key %d after key %d...\n", node4->key, key);
    listInsert(node4, searchResult);

    printf("Deleting key %d in the list...\n", key);
    listDelete(myList, searchResult);
  } else {
    printf("Key %d not found in the list.\n", key);
  }

  printf("Modified list:");
  for (Node *current = myList->head; current != NULL; current = current->next) {
    printf(" %d", current->key);
  }
  printf("\n");

  listDestroy(myList);

  return 0;
}
