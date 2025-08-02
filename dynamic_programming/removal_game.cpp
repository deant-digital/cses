#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  vector dp(n + 1, vector<ll>(n + 1));
  for (ll i{}; i < n; ++i) {
    dp[i][i + 1] = vec[i];
  }
  for (ll l{2}; l <= n; ++l) {
    for (ll i{0}; i + l <= n; ++i) {
      ll j{i + l};
      dp[i][j] = max(vec[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
                     vec[j - 1] + min(dp[i][j - 2], dp[i + 1][j - 1]));
    }
  }
  cout << dp[0][n] << '\n';
}
