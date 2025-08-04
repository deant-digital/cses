#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<array<ll, 3>> vec(n);
  for (auto& [b, a, p] : vec) {
    cin >> a >> b >> p;
  }
  sort(vec.begin(), vec.end());
  vector<ll> dp(vec.size() + 1);
  for (ll i{}; i < n; ++i) {
    ll idx{lower_bound(vec.begin(), vec.end(), array<ll, 3>{vec[i][1], 0, 0}) -
           vec.begin()};
    dp[i + 1] = max(dp[i], dp[idx] + vec[i][2]);
  }
  cout << dp.back() << '\n';
}
