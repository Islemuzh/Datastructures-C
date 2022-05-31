#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int bitcoin(int prices[], int n, int k) {
    int res=0;
    int i,j;
    int int_min=-99999;
    if (2*k>n) {
        // iterate over all day
        for (i=1;i < n;i++) {
            j = i-1;
            res = res + max(0, prices[i]-prices[j]);
        }
        return res;
    }
    // now create and fill the dp table
    // dp[i][used_k][ishold] = profit
    int dp[n][k+1][2];
    for (i=0;i<n;i++) {
        for (j=0;j<=k;j++) {
            dp[i][j][0] = int_min;
            dp[i][j][1] = int_min;
        }
    }
    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];
    for (i=1;i<n;i++) {
        for (j=0;j<=k; j++) {
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
            dp[i][j][1] = dp[i-1][j][1];
            if (j>0) {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
    }
    for (j=0;j<=k;j++) {
        res = max(res, dp[n-1][j][0]);
    }
    return res;
}

int main() {
  int prices[100];
  int i = 0;
  int k = 0;
  int n;
  printf("Number of transactions: ");
  scanf("%d", &k);
  printf(
      "Values of the prices list separated by spaces (non-number to stop): ");
  while (scanf("%d", &prices[i]) == 1) {
    i++;
  }
  n = i;
  int max_val = bitcoin(prices, n, k);
  printf("The maximum value is %d\n", max_val);
}