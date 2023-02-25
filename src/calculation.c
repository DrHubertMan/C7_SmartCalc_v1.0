#include "smartcalc.h"

void calculation(char *output, char answer) {
  double x_number = -10;
  if (answer == 'x') {
    for (int i = 0; i < 10; i++) {
      char tmp[MAX_STR];
      x_string(&output, x_number, tmp);
      printf("%.7f\n", calculation_core(tmp));
      x_number++;
    }
  } else {
    printf("%.7f\n", calculation_core(output));
  }
}

double calculation_core(char *output) {
  double result;
  Node_calc *stack = NULL;
  char buff[256] = {0};
  strcat(buff, output);
  //printf("%s\n", output);
  char *token = strtok(buff, " ");
  while (token) {
    if ((token[0] >= '0' && token[0] <= '9') ||
        (token[0] == '-' && token[1] >= '0' && token[1] <= '9')) {
      double value = atof(token);
      push_calc(&stack, value);
    } else if (token[0] == '+') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_1 + value_2);
    } else if (token[0] == '-') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_1 - value_2);
    } else if (token[0] == '*') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_1 * value_2);
    } else if (token[0] == '/') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_1 / value_2);
    } else if (token[0] == '^') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, pow(value_2, value_1));
      // } else if (token[0] == '%') {
      //   double value_1 = pop_calc(&stack);
      //   double value_2 = pop_calc(&stack);
      //   double mod;
      //   push_calc(&stack, value_1 % value_2);
    } else if (token[0] == 'A') {
      double value = pop_calc(&stack);
      push_calc(&stack, cos(value));
    } else if (token[0] == 'B') {
      double value = pop_calc(&stack);
      push_calc(&stack, sin(value));
    } else if (token[0] == 'C') {
      double value = pop_calc(&stack);
      push_calc(&stack, tan(value));
    } else if (token[0] == 'D') {
      double value = pop_calc(&stack);
      push_calc(&stack, acos(value));
    } else if (token[0] == 'E') {
      double value = pop_calc(&stack);
      push_calc(&stack, asin(value));
    } else if (token[0] == 'F') {
      double value = pop_calc(&stack);
      push_calc(&stack, atan(value));
    } else if (token[0] == 'G') {
      double value = pop_calc(&stack);
      push_calc(&stack, sqrt(value));
    } else if (token[0] == 'H') {
      double value = pop_calc(&stack);
      push_calc(&stack, log(value));
    } else if (token[0] == 'I') {
      double value = pop_calc(&stack);
      push_calc(&stack, log10(value));
    }
    token = strtok(NULL, " ");
  }
  result = pop_calc(&stack);
  return result;
}

// cos - A
// sin - B
// tan - C
// aco - D
// asi - E
// ata - F
// sqr - G
// ln - H
// log - I