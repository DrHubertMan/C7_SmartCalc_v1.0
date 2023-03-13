#include "calculation_module.h"

double credit_a(double sumCredit, int month, double percent);
int credit_d(double sumCredit, int month, double percent);

int main() {
  // char input[MAX_STR] = "(25.5 + 25.5 + 25.5)";
  // char output[MAX_STR];
  // char answer = 'c';
  // double result;

  double sumCred = 248000;
  int mont = 12;
  double percent = 16;
  double month_pay = credit_a(sumCred, mont, percent);
  for (int i = 1; i <= mont; i++) {
    printf("%d month - %.2f rub\n", i, month_pay);
  }
  printf("Overpay - %.2f rub\n", ((month_pay * mont) - sumCred));
  printf("Summ pay - %.2f rub\n", (month_pay * mont));
  credit_d(sumCred, mont, percent);
  // if (sorting_station(input, output) >= 0) {
  //   // printf("%s\n", output);
  //   calculation_c(output, answer, &result);
  //   printf("*%.7f*\n", result);
  // } else {
  //   printf("error\n");
  // }
  return 0;
}

double credit_a(double sumCredit, int month, double percent) {
  double result = -1;
  if (sumCredit > 0 && month > 0 && percent >= 0) {
    double ps = percent / (100 * 12);
    double znam = 1 - pow(1 + ps, -month);
    result = sumCredit * (ps / znam);
  }
  return result;
}

int credit_d(double sumCredit, int month, double percent) {
  int result = -1;
  if (sumCredit > 0 && month > 0 && percent >= 0) {
    double everymonth = sumCredit / month;
    double overpay = 0;
    double summPay = 0;
    for (int i = 0; i < month; i++) {
      double thatMount = everymonth + (sumCredit - (i * everymonth)) *
                                         (percent / 100) * 31 / 365;
      summPay += thatMount;
      printf("%d month - %.2f rub\n", i + 1, thatMount);
    }
    overpay = summPay - sumCredit;
    printf("Overpay - %.2f rub\nSumm pay - %.2f rub\n", overpay, summPay);
    result = 0;
  }
  return result;
}