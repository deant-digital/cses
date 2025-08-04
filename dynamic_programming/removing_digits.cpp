#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, LLONG_MAX);
  dp[0] = 0;
  for (ll i{1}; i <= n; ++i) {
    ll val{i};
    while (val > 0) {
      ll digit{val % 10};
      if (digit != 0) {
        dp[i] = min(dp[i], dp[i - digit] + 1);
      }
      val /= 10;
    }
  }
  cout << dp[n] << '\n';
}
