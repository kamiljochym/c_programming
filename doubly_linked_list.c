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

  newNode->next = (*head);

  newNode->prev = NULL;

  if ((*head) != NULL) {
    (*head)->prev = newNode;
  }

  (*head) = newNode;
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

  printf("printing node value: %d \n", head->next->data);

  return 0;
}
