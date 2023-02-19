#include "smartcalc.h"

int main() {

  char input[255] = "cos(2 + 5 + 6 * (3 + 5))";
  char output[255];
  if (sorting_station(input, output) >= 0) {
    //printf("%s\n", output);
    printf("%.2f", calculation(output));
  } else {
    printf("error\n");
  }
  return 0;
}
