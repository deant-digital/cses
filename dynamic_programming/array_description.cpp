#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  vector dp(n, vector<ll>(m + 2));
  if (vec[0] == 0) {
    fill(dp[0].begin() + 1, prev(dp[0].end()), 1);
  } else {
    dp[0][vec[0]] = 1;
  }
  for (ll i{1}; i < n; ++i) {
    for (ll j{1}; j <= m; ++j) {
      if (vec[i] == 0 || vec[i] == j) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] += dp[i - 1][j];
        dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= ll(1e9 + 7);
      }
    }
  }
  ll ans{accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL)};
  cout << ans % ll(1e9 + 7) << '\n';
}
