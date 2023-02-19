#include "smartcalc.h"

void push(Node **head, char sym) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->value = sym;
  tmp->next = (*head);
  (*head) = tmp;
}

char pop(Node **head) {
  Node *prev = NULL;
  char sym;
  if (head == NULL) {
    exit(-1);
  }
  prev = (*head);
  sym = prev->value;
  (*head) = (*head)->next;
  free(prev);
  return sym;
}
