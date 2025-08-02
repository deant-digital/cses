#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<array<ll, 3>> vec(n);
  map<ll, ll> mp;
  for (auto& [b, a, p] : vec) {
    cin >> a >> b >> p;
    mp[b] = 0;
  }
  sort(vec.begin(), vec.end());
  {
    ll i{};
    for (auto& [k, v] : mp) {
      v = i++;
    }
  }
  vector<ll> dp(n + 1);
  for (ll i{}; i < n; ++i) {
    auto it{mp.lower_bound(vec[i][1])};
    if (it != mp.begin()) {
      --it;
      ll idx{it->second};
      dp[i + 1] = max(dp[i], dp[idx + 1] + vec[i][2]);
    } else {
      dp[i + 1] = vec[i][2];
    }
  }
  cout << dp[n] << '\n';
}
