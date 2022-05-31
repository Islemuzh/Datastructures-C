#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int roses_split(int prices[], int n) {
  int profit[n + 1];
  int i, j;
  for (i = 0; i <= n; i++) {
    profit[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    // divide the i roses into two bouquets: j and i-j
    // take the maximum
    for (j = 1; j <= i; j++) {
      profit[i] = max(profit[i], prices[j - 1] + profit[i - j]);
    }
  }
  return profit[n];
}

int main() {
  int prices[100];
  int i = 0;
  int n = 0;
  printf("Number of products in total: ");
  scanf("%d", &n);
  printf(
      "Values of the prices list separated by spaces (non-number to stop): ");
  while (scanf("%d", &prices[i]) == 1) {
    i++;
  }
  int max_val = roses_split(prices, n);
  printf("The maximum value is %d\n", max_val);
}