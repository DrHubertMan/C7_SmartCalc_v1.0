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
  char input[255] = "(2 + 4 * (8 + 9) / 2) + (7 * (4 + 6))";
  char output[255];
  sort(input, output, &stack);
  printf("%s\n", output);
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

// * = 42
// + = 43
// - = 45
// / = 47
// ^ = 94

void sort(char *input, char *output, Node **stack) {
  int output_sym_counter = 0;
  int input_leng = strlen(input);
  for (int i = 0; i < input_leng; i++) {
    if (input[i] == ' ') {
      continue;
    } else if (input[i] == '(') {
       push(stack, input[i]);
    
    } else if (char_is_operator(input[i])) {
      while (view_last_char_in_stack(*stack) == 94) {
        output[output_sym_counter] = pop(stack);
        output_sym_counter++;
      }

      if (input[i] == 43 || input[i] == 45) {
        while (char_is_operator(view_last_char_in_stack(*stack))) {
          output[output_sym_counter] = pop(stack);
          output_sym_counter++;
        }
      } else if (input[i] == 42 || input[i] == 47) {
        while (view_last_char_in_stack(*stack) == input[i]) {
          output[output_sym_counter] = pop(stack);
          output_sym_counter++;
        }
      }
      push(stack, input[i]);
    } else if (input[i] == ')') {
      while (view_last_char_in_stack(*stack) != '(') {
        if (char_is_operator(view_last_char_in_stack(*stack))) {
          output[output_sym_counter] = pop(stack);
          output_sym_counter++;
        }
      }
      // if (view_last_char_in_stack(*stack) != ')') {
      //   pop(stack);
      // }
    } else {
      output[output_sym_counter] = input[i];
      output_sym_counter++;
    }
  }
  while ((*stack)->next) {
    output[output_sym_counter] = pop(stack);
    output_sym_counter++;
  }
}