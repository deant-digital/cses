#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll& x0 : vec) {
    cin >> x0;
  }
  vector<ll> dp(x + 1);
  dp[0] = 1;
  for (ll x0 : vec) {
    for (ll j{x0}; j <= x; ++j) {
      dp[j] += dp[j - x0];
      dp[j] %= ll(1e9 + 7);
    }
  }
  cout << dp[x] << '\n';
}
