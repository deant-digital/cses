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
  vector<ll> dp(x + 1, LLONG_MAX);
  dp[0] = 0;
  for (ll i{1}; i <= x; ++i) {
    for (ll x0 : vec) {
      if (i - x0 >= 0 && dp[i - x0] != LLONG_MAX) {
        dp[i] = min(dp[i], dp[i - x0] + 1);
      }
    }
  }
  if (dp[x] == LLONG_MAX) {
    cout << -1 << '\n';
    return 0;
  }
  cout << dp[x] << '\n';
}
