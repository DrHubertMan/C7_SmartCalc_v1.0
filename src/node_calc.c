#include "smartcalc.h"

void push_calc(Node_calc **head, double number) {
  Node_calc *tmp = (Node_calc *)malloc(sizeof(Node_calc));
  tmp->value = number;
  tmp->next = (*head);
  (*head) = tmp;
}

double pop_calc(Node_calc **head) {
  Node_calc *prev = NULL;
  double number;
  if (head == NULL) {
    exit(-1);
  }
  prev = (*head);
  number = prev->value;
  (*head) = (*head)->next;
  free(prev);
  return number;
}
