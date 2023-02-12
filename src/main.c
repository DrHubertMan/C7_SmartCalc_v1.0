#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node {
  char value;
	struct Node *next;
} Node;

void push (Node **head, char sym);
char pop (Node **head);
void sort(char *input, char *output, Node **stack);
char view_last_char_in_stack(Node *head);
int char_is_operator(char sym);

int main() {
  Node *stack = NULL;
  char input[255] = "(2 + 4 * (12 + 14) / 2) + (13 * (4 + 6))";
  char output[255];
  //sort(input, output, &stack);
  //printf("%s\n", output);
  return 0;
}

void push (Node **head, char sym) {
  Node *tmp = (Node*)malloc(sizeof(Node));
  tmp->value = sym;
  tmp->next = (*head);
  (*head) = tmp;
}

char pop (Node **head) {
  Node *prev = NULL;
  char sym;
  if (head == NULL) {
    exit (-1);
  }
  prev = (*head);
  sym = prev->value;
  (*head) = (*head)->next;
  free(prev);
  return sym;
}

char view_last_char_in_stack(Node *head) {
  return head->value;
}

int char_is_operator(char sym) {
  return (sym == 42 || sym == 43 || sym == 45 || sym == 47 || sym == 94) ? 1 : 0;
}

void sort(char *input, char *output, Node **stack) {
  for (int i = 0; i < 255; i++) {
    if (input[i] == ' ') {
      continue;
    } else if (input[i] == '(') {
      push(stack, input[i]);
    } else if (char_is_operator)
  }
}