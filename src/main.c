#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define S21_EPS 1e-6

typedef struct Node {
  char value;
  struct Node *next;
} Node;

void push(Node **head, char sym);
char pop(Node **head);
int sort(char *input, char *output);
int char_is_operator(char sym);
int char_is_number(char sym);
int is_left_associative(char sym);
char is_function(char *sym);
int priority(char c);


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

int char_is_operator(char sym) {
  return (sym == 42 || sym == 43 || sym == 45 || sym == 47 || sym == 94 ||
          sym == 37)
             ? 1
             : 0;
}

int char_is_number(char sym) { return (sym >= '0' && sym <= '9') ? 1 : 0; }

char is_function(char *str) {
  char result = -1;
  if (strncmp(str, "cos", 3) == 0) {
    result = 'A';
  } else if (strncmp(str, "sin", 3) == 0) {
    result = 'B';
  } else if (strncmp(str, "tan", 3) == 0) {
    result = 'C';
  } else if (strncmp(str, "acos", 4) == 0) {
    result = 'D';
  } else if (strncmp(str, "asin", 4) == 0) {
    result = 'E';
  } else if (strncmp(str, "atan", 4) == 0) {
    result = 'F';
  } else if (strncmp(str, "sqrt", 4) == 0) {
    result = 'G';
  } else if (strncmp(str, "ln", 2) == 0) {
    result = 'H';
  } else if (strncmp(str, "log", 3) == 0) {
    result = 'I';
  }
  return result;
}

int is_function_in_stack(char sym) {
  return (sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' ||
          sym == 'F' || sym == 'G' || sym == 'H' || sym == 'I')
             ? 1
             : 0;
}
// * = 42
// + = 43
// - = 45
// / = 47
// ^ = 94
// % = 37

int is_left_associative(char sym) {
  return (sym == '*' || sym == '/' || sym == '+' || sym == '-' || sym == '%')
             ? 1
             : 0;
}

int priority(char c) {
  int result = 0;
  if (c == '^') {
    result = 4;
  } else if (c == '*' || c == '/' || c == '%') {
    result = 3;
  } else if (c == '+' || c == '-') {
    result = 2;
  } else if (c == '=') {
    result = 1;
  }
  return result;
}

// cos - A
// sin - B
// tan - C
// aco - D
// asi - E
// ata - F
// sqr - G
// ln - E
// log - K

int sort(char *input, char *output) {
  int exit_code = 0;
  Node *stack = NULL;
  int output_sym_counter = 0;
  int input_leng = strlen(input);
  for (int i = 0; i < input_leng; i++) {

    if (input[i] == ' ') {
      continue;

    } else if (char_is_number(input[i])) {
      output[output_sym_counter] = input[i];
      output_sym_counter++;

    } else if (input[i] == '(') {
      push(&stack, input[i]);

    } else if (is_function(&input[i]) != -1) {
      push(&stack, is_function(&input[i]));

    } else if (input[i] == ',') {
      while (stack && stack->value != '(') {
        if (stack && char_is_operator(stack->value)) {
          output[output_sym_counter] = pop(&stack);
          output_sym_counter++;
        }
      }
      if (stack && stack->value != '(') {
        exit_code = -1;
        break;
      }

    } else if (char_is_operator(input[i])) {
      while (stack && char_is_operator(stack->value)) {
        if ((is_left_associative(input[i]) &&
             (priority(input[i]) <= priority(stack->value))) ||
            (!is_left_associative(input[i]) &&
             (priority(input[i]) < priority(stack->value)))) {
          output[output_sym_counter] = pop(&stack);
          output_sym_counter++;
        } else {
          break;
        }
      }
      push(&stack, input[i]);

    } else if (input[i] == ')') {
      while (stack && stack->value != '(') {
        if (char_is_operator(stack->value)) {
          output[output_sym_counter] = pop(&stack);
          output_sym_counter++;
        }
      }
      if (stack && stack->value == '(') {
        pop(&stack);
      } 
      else {
        exit_code = -1;
      }
      if (stack && is_function_in_stack(stack->value)) {
        output[output_sym_counter] = pop(&stack);
        output_sym_counter++;
      } 
    }
  }

  while (stack) {
    if (char_is_operator(stack->value)) {
      output[output_sym_counter] = pop(&stack);
      output_sym_counter++;
    } else {
      exit_code = -1;
      break;
    }
  }
  return exit_code;
}

int main() {

  char input[255] = "sin(2 * 3 / (5 - 2))";
  char output[255];
  if (sort(input, output) >= 0) {
    printf("%s\n", output);
  } else {
    printf("error\n");
  }
  return 0;
}
