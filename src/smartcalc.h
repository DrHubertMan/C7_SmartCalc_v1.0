#ifndef SRC_SMARTCALC_H
#define SRC_SMARTCALC_H
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define S21_EPS 1e-6

typedef struct Node {
  char value;
  struct Node *next;
} Node;

typedef struct Node_calc {
  double value;
  struct Node_calc *next;
} Node_calc;

void push(Node **head, char sym);
char pop(Node **head);
int sorting_station(char *input, char *output);
int char_is_operator(char sym);
int char_is_number(char sym);
int is_left_associative(char sym);
char is_function(char *sym);
int is_function_in_stack(char sym);
int priority(char c);
void push_calc(Node_calc **head, double number);
double pop_calc(Node_calc **head);
double calculation(char *output);
void type_in_output(char *output, int *i, char sym);

#endif  // SRC_SMARTCALC_H
