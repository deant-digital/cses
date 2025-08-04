#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll sum{n * (n + 1) / 2};
  if (sum % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }
  ll t{sum / 2};
  vector<ll> dp(t + 1);
  dp[0] = 1;
  for (ll x{1}; x <= n; ++x) {
    for (ll x0{t}; x0 - x >= 0; --x0) {
      dp[x0] += dp[x0 - x];
      dp[x0] %= ll(1e9 + 7);
    }
  }
  cout << dp[t] * ll(5e8 + 4) % ll(1e9 + 7) << '\n';
}
