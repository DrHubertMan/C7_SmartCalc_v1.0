#include "smartcalc.h"

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