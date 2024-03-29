#include "calculation_module.h"

/*!
         Проверяет является ли передаваемый символ оператором.
  \param[in] sym - проверяемый символ.
  \return Истина или ложь (1 или 0).
*/
int char_is_operator(char sym) {
  return (sym == '*' || sym == '+' || sym == '-' || sym == '/' || sym == '^' ||
          sym == '%')
             ? 1
             : 0;
}

/*!
         Проверяет является ли передаваемый символ цифрой.
  \param[in] sym - проверяемый символ.
  \return Истина или ложь (1 или 0).
*/
int char_is_number(char sym) { return (sym >= '0' && sym <= '9') ? 1 : 0; }

/*!
         Проверяет является ли передаваемая строка функцией.
  \param[in] *str - указатель на проверяемою строку.
  \return В случае, если передаваемая строка является функцией возвращает символ
  соответствующий функции.
*/
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

/*!
         Проверяет является ли передаваемый символ из стека символом функции.
  \param[in]  sym - проверяемый символ.
  \return Истина или ложь (1 или 0).
*/
int is_function_in_stack(char sym) {
  return (sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' ||
          sym == 'F' || sym == 'G' || sym == 'H' || sym == 'I')
             ? 1
             : 0;
}

/*!
         Проверяет является ли передаваемый символ(оператор) левоасоциативным.
  \param[in]  sym - проверяемый символ.
  \return Истина или ложь (1 или 0).
*/
int is_left_associative(char sym) {
  return (sym == '*' || sym == '/' || sym == '+' || sym == '-' || sym == '%')
             ? 1
             : 0;
}

/*!
        Определяет приоритет предаваемого оператора.
  \param[in]  c - проверяемый символ.
  \return Значение приоритета от 1 до 4.
*/
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

/*!
        Записывает символ по определенному индексу передаваемого массива
  символов.

  После того как символ будет записан увеличивает индекс на один.
  \param[in, out] *output - указатель на строку (массив символов).
  \param[in, out] *i - указатель на индекс массива.
  \param[in] sym - записываемый символ в массив.
*/
void type_in_output(char *output, int *i, char sym) {
  output[*i] = sym;
  *i += 1;
}

/*!
        В исходной строке содержащей символ Х, заменяет его на значение.

  При получении строки содержащую переменную Х, переводит передаваемое число
  типа double в строку, затем подставляет эту строку вместо Х. \param[in]
  **output - указатель на указатель строки содержащей Х. \param[in] x_number -
  Число которое необходимо записать в строку. \param[in, out] *result -
  Указатель на преобразованную строку.
*/
void x_string(char **output, double x_number, char *result) {
  char str[MAX_STR];
  char buff[MAX_STR];
  double_to_string(x_number, str, 7);  // 7- precision
  // sprintf(str, "%.7f", x_number);
  int x_pos = 0;
  int leng = strlen(*output);
  for (int i = 0; i < leng; i++) {
    if ((*output)[i] == 'x') {
      x_pos = i;
      break;
    }
  }
  strncpy(buff, *output, x_pos);
  buff[x_pos] = '\0';
  x_pos++;
  strcat(buff, str);
  strcat(buff, *output + x_pos);
  memset(result, 0, MAX_STR);
  strcat(result, buff);
}

/*!
        Преобразует число типа double в строку, с возможностью задать точность.

  \param[in] num - Преобразовываемое число.
  \param[in] *str - Строка в которую запишется преобразованное значение.
  \param[in, out] precision - Точность преобразования(кол-во знаков после
  точки).
*/
void double_to_string(double num, char *str, int precision) {
  num = round(num * pow(10, precision)) / pow(10, precision);
  int integerPart = (int)num;
  double fractionalPart = num - integerPart;

  if (integerPart < 0) {
    *str++ = '-';
    integerPart = -integerPart;
    num = -num;
    fractionalPart = -fractionalPart;
  }

  int index = 0;
  while (integerPart > 0) {
    str[index++] = (char)(integerPart % 10) + '0';
    integerPart /= 10;
  }
  int length = index;

  for (int i = 0; i < index / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }

  if (precision > 0) {
    str[length++] = '.';
    for (int i = 0; i < precision; i++) {
      fractionalPart *= 10;
      int digit = (int)fractionalPart;
      str[length++] = (char)digit + '0';
      fractionalPart -= digit;
    }
  }
  str[length] = '\0';
  if (fabs(num) < (1e-6)) {
    str[0] = '0';
    str[1] = '\0';
  }
}

/*!
        Создает новый узел односвязного списка

  \param[in]  **head - Указатель на верхний узел стека.
  \param[in] sym - Значение помещаемое на стек.
*/
void push(Node **head, char sym) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->value = sym;
  tmp->next = (*head);
  (*head) = tmp;
}

/*!
        Удаляет верхний узел стека.

  \param[in]  **head - Указатель на верхний узел стека.
  \return - Значение типа char, хранившееся в стеке.
*/
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

/*!
        Создает новый узел односвязного списка для вычисления выражения в
  постфиксной нотации.

  \param[in]  **head - Указатель на верхний узел стека.
  \param[in] number - Значение помещаемое на стек.
*/
void push_calc(Node_calc **head, double number) {
  Node_calc *tmp = (Node_calc *)malloc(sizeof(Node_calc));
  tmp->value = number;
  tmp->next = (*head);
  (*head) = tmp;
}

/*!
        Удаляет верхний узел стека для вычисления выражения в постфиксной
  нотации.

  \param[in]  **head - Указатель на верхний узел стека.
  \return - Значение типа double, хранившееся в стеке.
*/
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

/*!
        Преобразует выражение входной строки.

  Выражение записанное в инфиксной нотации, записанное во входной строке,
  используя стек, преобразуется и записывается в выходную строку. \param[in]
   *input - Указатель на входную строку. \param[out]  *output - Указатель на
  выходную строку. \return - Код выполнения алгоритма (0 - Успех, любое другое
  значение - алгоритм завершен некоректно).
*/
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
      if (is_function(&input[i]) == 'H') {
        i += 1;
      } else {
        i += 2;
      }

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
      while (stack) {
        pop(&stack);
      }
      exit_code = -1;
      break;
    }
  }
  output[output_sym_counter] = '\0';
  return exit_code;
}

/*!
        Вычисляет выражение с переменной Х.

  Получаемт выражение записанное в постфиксной нотации содержащее переменную Х.
  Вызывает функцию подставляющую в исходную строку значение Х. Затем вызывает
  функцию вычисляющую полученное выражение. \param[in]  *output - Указатель на
  строку содержащую выражение с переменной Х. \param[in]  x_value - Значение
  переменной Х. \return - Вычисленное выражение.
*/
double calculation_x_str(char *output, double x_value) {
  double result = 0;
  char x_string_tmp[MAX_STR];
  x_string(&output, x_value, x_string_tmp);
  result = calculation_core(x_string_tmp);
  return result;
}

/*!
        Вычисляет выражение записанное в постфиксной нотации во входящей строке.

  Получает в качестве аргумента строку, создается стек, входная строка режется
  на токены в зависимости от того, что в токене находится вычисляет выражение.
  \param[in]  *output - Указатель на строку содержащую выражение в постфиксной
  нотации. \return - Вычисленное выражение.
*/
double calculation_core(char *output) {
  double result = 0;
  Node_calc *stack = NULL;
  push_calc(&stack, result);
  char buff[256] = {0};
  strcat(buff, output);
  char *token = strtok(buff, " ");
  while (token) {
    if ((token[0] >= '0' && token[0] <= '9') ||
        (token[0] == '-' && token[1] >= '0' && token[1] <= '9')) {
      double value = my_atof(token);
      push_calc(&stack, value);
    } else if (token[0] == '+') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_2 + value_1);
    } else if (token[0] == '-') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_2 - value_1);
    } else if (token[0] == '*') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_2 * value_1);
    } else if (token[0] == '/') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, value_2 / value_1);
    } else if (token[0] == '^') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, pow(value_2, value_1));
    } else if (token[0] == '%') {
      double value_1 = pop_calc(&stack);
      double value_2 = pop_calc(&stack);
      push_calc(&stack, (int)value_2 % (int)value_1);
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
  while (stack) {
    pop_calc(&stack);
  }

  return result;
}

/*!
        Переводит число записанное в строковом формате в тип double.

  \param[in]  *output - Указатель на строку содержащую число в строковом
  формате. \return - Преобразованное число типа double.
*/
double my_atof(char *str) {
  double value = 0.0;
  int sign = 1;
  int i = 0;
  while (isspace(str[i])) {
    i++;
  }
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }
  while (isdigit(str[i])) {
    value = value * 10.0 + (str[i] - '0');
    i++;
  }
  if (str[i] == '.') {
    double factor = 1.0;
    i++;
    while (isdigit(str[i])) {
      factor *= 0.1;
      value = value + (str[i] - '0') * factor;
      i++;
    }
  }
  return sign * value;
}
