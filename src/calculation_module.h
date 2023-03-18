/*!
\file
\brief Заголовочный файл с описанием структур и функций,
используемых для преобразования входной строки, содержащей выражение в инфиксной
нотации, в выходную строку, содержащую выражение в постфиксной нотации, с
последующим ее вычислением.
*/
#ifndef SRC_SMARTCALC_H
#define SRC_SMARTCALC_H

#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*!
        \brief Макрос используется для сравнения чисел с плавающей точкой.
*/
#define S21_EPS 1e-6

/*!
        \brief Макрос используется для задания максимальной длинны массива
   символов.
*/
#define MAX_STR 255

/*!
        \brief Структура используемая для создания односвязного списка

        Данная структура служит для создания стека на основе односвязного
  списка. Стек используется в алгоритме сортировочной станции, для
  преобразования выражения в постфиксной нотации. \param value - символ
  обрабатываемой строки в стеке.
*/
typedef struct Node {
  char value;
  struct Node *next;
} Node;

/*!
        \brief Структура используемая для создания односвязного списка

        Данная структура служит для создания стека на основе односвязного
  списка. Стек используется для вычисления выражения записаного в строке в
  постфиксной нотации. \param value - численное значение операнда в стеке.
*/
typedef struct Node_calc {
  double value;
  struct Node_calc *next;
} Node_calc;

double my_atof(char *str);
void x_string(char **output, double x_number, char *result);
void push(Node **head, char sym);
char pop(Node **head);
int char_is_operator(char sym);
int char_is_number(char sym);
int is_left_associative(char sym);
char is_function(char *sym);
int is_function_in_stack(char sym);
int priority(char c);
void push_calc(Node_calc **head, double number);
double pop_calc(Node_calc **head);
void type_in_output(char *output, int *i, char sym);
int sorting_station(char *input, char *output);
double calculation_x_str(char *output, double x_value);
double calculation_core(char *output);
void double_to_string(double num, char *str, int precision);

#endif  // SRC_SMARTCALC_H
