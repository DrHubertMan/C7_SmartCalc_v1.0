#include "smartcalc.h"

int sorting_station(char *input, char *output) {
  int exit_code = 0;
  Node *stack = NULL;
  int output_sym_counter = 0;
  int input_leng = strlen(input);
  for (int i = 0; i < input_leng; i++) {
    if (input[i] == ' ') {
      continue;

    } else if (char_is_number(input[i]) || input[i] == 'x') {
      while (char_is_number(input[i]) || input[i] == 'x') {
        type_in_output(output, &output_sym_counter, input[i]);
        i++;
      }
      i--;
      if (input[i + 1] == '.' && input[i] != 'x') {
        if (char_is_number(input[i + 2])) {
          i++;
          type_in_output(output, &output_sym_counter, input[i]);
          while (char_is_number(input[i + 1])) {
            i++;
            type_in_output(output, &output_sym_counter, input[i]);
          }
        } else {
          exit_code = -1;
          break;
        }
      }
      type_in_output(output, &output_sym_counter, ' ');

    } else if (input[i] == '(') {
      push(&stack, input[i]);

    } else if (is_function(&input[i]) != -1) {
      push(&stack, is_function(&input[i]));
      i = i + 2;

    } else if (input[i] == ',') {
      while (stack && stack->value != '(') {
        if (stack && char_is_operator(stack->value)) {
          type_in_output(output, &output_sym_counter, pop(&stack));
          type_in_output(output, &output_sym_counter, ' ');
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
          type_in_output(output, &output_sym_counter, pop(&stack));
          type_in_output(output, &output_sym_counter, ' ');
        } else {
          break;
        }
      }
      push(&stack, input[i]);

    } else if (input[i] == ')') {
      while (stack && stack->value != '(') {
        if (char_is_operator(stack->value)) {
          type_in_output(output, &output_sym_counter, pop(&stack));
          type_in_output(output, &output_sym_counter, ' ');
        }
      }
      if (stack && stack->value == '(') {
        pop(&stack);
      } else {
        exit_code = -1;
      }
      if (stack && is_function_in_stack(stack->value)) {
        type_in_output(output, &output_sym_counter, pop(&stack));
        type_in_output(output, &output_sym_counter, ' ');
      }
    }
  }

  while (stack) {
    if (char_is_operator(stack->value)) {
      type_in_output(output, &output_sym_counter, pop(&stack));
      type_in_output(output, &output_sym_counter, ' ');
    } else {
      exit_code = -1;
      break;
    }
  }
  // destroy stack()
  output[output_sym_counter] = '\0';
  return exit_code;
}
