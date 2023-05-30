#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;

  struct Node *next;

  struct Node *prev;
};

void insertFront(struct Node **head, int val) {

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;

  newNode->next = *head;

  newNode->prev = NULL;

  if ((*head) != NULL) {
    (*head)->prev = newNode;
  }

  (*head) = newNode;
}

void insertAfter(struct Node *prev, int val) {

  if (prev == NULL) {
    printf("Previous Node cannot be NULL");
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->data = val;
  newNode->next = prev->next;
  newNode->prev = prev;
  prev->next = newNode;

  if (newNode->next != NULL) {
    newNode->next->prev = newNode;
  }
}

void insertEnd(struct Node **head, int val) {

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  /* struct Node *t = (struct Node *)malloc(sizeof(struct Node)); */

  struct Node *t = *head;

  while (t->next != NULL) {
    t = t->next;
  }
  newNode->data = val;
  newNode->next = NULL;
  t->next = newNode;
  newNode->prev = t;
}

void deleteNode(struct Node **head, struct Node *nodeToDelete) {

  if (nodeToDelete == NULL) {
    printf("node to delete cannot be NULL");
    return;
  }
  // if node is at the beginning
  if (nodeToDelete->prev == NULL) {
    (*head) = (*head)->next;
  }
  // if node is at the end
  else if (nodeToDelete->next == NULL) {
    nodeToDelete->prev->next = NULL;
  } else {
    struct Node *t = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;
  }

  free(nodeToDelete);
}

// print the doubly linked list
void displayList(struct Node *node) {
  struct Node *last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
  printf("Hello world\n");

  struct Node *head = NULL;
  /* head->data = 5; */

  /* struct Node *secondItem; */
  /* secondItem->data = 9; */

  /* head->next = secondItem; */

  /* secondItem->prev = head; */

  insertFront(&head, 12);
  insertFront(&head, 99);
  insertEnd(&head, 44);
  insertAfter(head->next, 77);
  deleteNode(&head, head->next);
  insertAfter(head->next, 15);
  deleteNode(&head, head->next->next->next);
  displayList(head);

  printf("printing node value: %d \n", head->next->data);
  if (head->next->next->next == NULL) {
    printf("head->next is NULL");
  }

  return 0;
}
