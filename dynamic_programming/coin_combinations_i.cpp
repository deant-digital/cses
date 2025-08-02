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
  for (ll i{1}; i <= x; ++i) {
    for (ll x0 : vec) {
      if (i - x0 >= 0) {
        dp[i] += dp[i - x0];
        dp[i] %= ll(1e9 + 7);
      }
    }
  }
  cout << dp[x] << '\n';
}
