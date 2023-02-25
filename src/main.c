#include "smartcalc.h"

int main() {
  char input[MAX_STR] = "2.9 + 5.2 + x * (3.5 + 5)";
  char output[MAX_STR];
  char answer = 'x';
  if (sorting_station(input, output) >= 0) {
    //printf("%s\n", output);
    calculation(output, answer);
  } else {
    printf("error\n");
  }
  return 0;
}
