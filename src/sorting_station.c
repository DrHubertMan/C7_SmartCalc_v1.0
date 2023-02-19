#include "smartcalc.h"

void type_in_output(char *output, int *i, char sym) {
  output[*i] = sym;
  *i += 1;
}

int sorting_station(char *input, char *output) {
  int exit_code = 0;
  Node *stack = NULL;
  int output_sym_counter = 0;
  int input_leng = strlen(input);
  for (int i = 0; i < input_leng; i++) {
    if (input[i] == ' ') {
      continue;

    } else if (char_is_number(input[i])) {
      type_in_output(output, &output_sym_counter, input[i]);
      // output[output_sym_counter] = input[i];
      // output_sym_counter++;
      if (input[i + 1] == '.') {
        if (char_is_number(input[i + 2])) {
          i++;
          output[output_sym_counter] = input[i];
          output_sym_counter++;
          while (char_is_number(input[i + 1])) {
            i++;
            output[output_sym_counter] = input[i];
            output_sym_counter++;
          }
        } else {
          exit_code = -1;
          break;
        }
      }
      output[output_sym_counter] = ' ';
      output_sym_counter++;

    } else if (input[i] == '(') {
      push(&stack, input[i]);

    } else if (is_function(&input[i]) != -1) {
      push(&stack, is_function(&input[i]));
      i = i + 2;

    } else if (input[i] == ',') {
      while (stack && stack->value != '(') {
        if (stack && char_is_operator(stack->value)) {
          output[output_sym_counter] = pop(&stack);
          output_sym_counter++;
          output[output_sym_counter] = ' ';
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
          output[output_sym_counter] = ' ';
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
          output[output_sym_counter] = ' ';
          output_sym_counter++;
        }
      }
      if (stack && stack->value == '(') {
        pop(&stack);
      } else {
        exit_code = -1;
      }
      if (stack && is_function_in_stack(stack->value)) {
        output[output_sym_counter] = pop(&stack);
        output_sym_counter++;
        output[output_sym_counter] = ' ';
        output_sym_counter++;
      }
    }
  }

  while (stack) {
    if (char_is_operator(stack->value)) {
      output[output_sym_counter] = pop(&stack);
      output_sym_counter++;
      output[output_sym_counter] = ' ';
      output_sym_counter++;
    } else {
      exit_code = -1;
      break;
    }
  }
  // destroy stack()
  output[output_sym_counter] = '\0';
  return exit_code;
}
