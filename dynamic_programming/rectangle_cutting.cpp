#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  vector dp(a + 1, vector<ll>(b + 1, LLONG_MAX));
  for (ll i{}; i <= min(a, b); ++i) {
    dp[i][i] = 0;
  }
  for (ll i{1}; i <= a; ++i) {
    for (ll j{1}; j <= b; ++j) {
      for (ll k{1}; k < i; ++k) {
        if (dp[k][j] == LLONG_MAX || dp[i - k][j] == LLONG_MAX) {
          continue;
        }
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      for (ll k{1}; k < j; ++k) {
        if (dp[i][k] == LLONG_MAX || dp[i][j - k] == LLONG_MAX) {
          continue;
        }
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }
  cout << dp[a][b] << '\n';
}
