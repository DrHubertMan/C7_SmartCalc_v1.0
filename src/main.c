#include "smartcalc.h"

int main() {
  char input[512] = "cos(2.9 + 5.2 + 6.4 * (3.5 + 5))";
  char output[512];
  if (sorting_station(input, output) >= 0) {
    printf("%s\n", output);
    // printf("%f\n", calculation(output));
  } else {
    printf("error\n");
  }
  return 0;
}
