#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void handle(vector<ll>& vec, ll cur, ll nxt, ll row, ll n) {
  if (row >= n) {
    vec.push_back(nxt);
    return;
  }
  if (((cur >> row) & 1) == 1) {
    handle(vec, cur, nxt, row + 1, n);
  } else {
    handle(vec, cur, nxt | (1LL << row), row + 1, n);
    if (row + 1 < n && ((cur >> (row + 1)) & 1) == 0) {
      handle(vec, cur, nxt, row + 2, n);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> trans(1LL << n);
  for (ll i{}; i < trans.size(); ++i) {
    handle(trans[i], i, 0, 0, n);
  }
  vector<ll> dp(1LL << n);
  dp[0] = 1;
  while (m-- > 0) {
    vector<ll> nxt(dp.size());
    for (ll i{}; i < dp.size(); ++i) {
      if (dp[i] > 0) {
        for (ll mask : trans[i]) {
          nxt[mask] += dp[i];
          nxt[mask] %= ll(1e9 + 7);
        }
      }
    }
    dp.swap(nxt);
  }
  cout << dp[0] << '\n';
}
