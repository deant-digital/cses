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
  vector<ll> left(n, -1);
  {
    vector<ll> stk;
    for (ll i{}; i < n; ++i) {
      while (!stk.empty() && vec[stk.back()] <= vec[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        left[i] = stk.back();
      }
      stk.push_back(i);
    }
  }
  vector<ll> right(n, -1);
  {
    vector<ll> stk;
    for (ll i{n - 1}; i >= 0; --i) {
      while (!stk.empty() && vec[stk.back()] <= vec[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        right[i] = stk.back();
      }
      stk.push_back(i);
    }
  }
  vector<array<ll, 2>> order(n);
  for (ll i{}; i < n; ++i) {
    order[i] = {vec[i], i};
  }
  sort(order.rbegin(), order.rend());
  vector<ll> dp(n, 1);
  ll ans{};
  for (auto [val, idx] : order) {
    if (left[idx] != -1) {
      dp[idx] = max(dp[idx], dp[left[idx]] + 1);
    }
    if (right[idx] != -1) {
      dp[idx] = max(dp[idx], dp[right[idx]] + 1);
    }
    ans = max(ans, dp[idx]);
  }
  cout << ans << '\n';
}
