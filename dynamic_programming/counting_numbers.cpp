#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string str;
ll dp[19][11][2];
ll dfs(ll idx, ll last, ll tight) {
  if (idx >= str.size()) {
    return 1;
  }
  ll& x{dp[idx][last][tight]};
  if (x != -1) {
    return x;
  }
  ll ub{tight == 0 ? 9 : str[idx] - '0'};
  ll res{};
  if (last == 10) {
    res += dfs(idx + 1, 10, 0);
  }
  for (ll i{}; i <= ub; ++i) {
    if (last == 10 && i == 0) {
      continue;
    }
    if (i == last) {
      continue;
    }
    res += dfs(idx + 1, i, tight == 1 && i == ub ? 1 : 0);
  }
  x = res;
  return res;
}
ll solve(ll x) {
  if (x < 0) {
    return 0;
  }
  str = to_string(x);
  memset(dp, -1, sizeof(dp));
  return dfs(0, 10, 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << '\n';
}
