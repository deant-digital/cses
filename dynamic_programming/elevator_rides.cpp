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
  vector<array<ll, 2>> dp(1LL << n, {LLONG_MAX, 0});
  dp[0] = {1, 0};
  for (ll i{1}; i < dp.size(); ++i) {
    for (ll j{}; j < n; ++j) {
      if (((i >> j) & 1) == 1) {
        ll k{i ^ (1LL << j)};
        auto [cnt, wgt]{dp[k]};
        if (wgt + vec[j] <= x) {
          wgt += vec[j];
        } else {
          ++cnt;
          wgt = vec[j];
        }
        dp[i] = min(dp[i], {cnt, wgt});
      }
    }
  }
  cout << dp.back()[0] << '\n';
}
