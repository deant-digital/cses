#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (ll i{1}; i <= n; ++i) {
    for (ll j{1}; j <= 6 && i - j >= 0; ++j) {
      dp[i] += dp[i - j];
      dp[i] %= ll(1e9 + 7);
    }
  }
  cout << dp[n] << '\n';
}
