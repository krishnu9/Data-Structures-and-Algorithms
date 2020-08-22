// Page: 398
#include <bits/stdc++.h>
using namespace std;
int dp[100001];
// dp[i] = length of LIS ending at i.
int LIS(int *a, int n) {

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }
  return *max_element(dp, dp + n);
}

int main() {

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = LIS(a, n);
  cout << ans << '\n';

  return 0;
}
