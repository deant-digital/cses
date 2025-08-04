#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<string> mat(n);
  for (auto& row : mat) {
    cin >> row;
  }
  vector dp(n + 1, vector<ll>(n + 1));
  dp[0][1] = 1;
  for (ll i{1}; i <= n; ++i) {
    for (ll j{1}; j <= n; ++j) {
      if (mat[i - 1][j - 1] == '*') {
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      dp[i][j] %= ll(1e9 + 7);
    }
  }
  cout << dp[n][n] << '\n';
}
