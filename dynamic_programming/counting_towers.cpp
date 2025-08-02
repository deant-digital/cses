#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  vector<ll> vec(t);
  for (ll& n : vec) {
    cin >> n;
  }
  ll mx{*max_element(vec.begin(), vec.end())};
  vector<array<ll, 2>> dp(mx + 1);
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (ll i{2}; i <= mx; ++i) {
    dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] * 1;
    dp[i][0] %= ll(1e9 + 7);
    dp[i][1] = dp[i - 1][0] * 1 + dp[i - 1][1] * 4;
    dp[i][1] %= ll(1e9 + 7);
  }
  for (ll n : vec) {
    cout << (dp[n][0] + dp[n][1]) % ll(1e9 + 7) << '\n';
  }
}
