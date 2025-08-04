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
  map<ll, ll> mp;
  for (ll i{}; i < n; ++i) {
    auto it{mp.find(vec[i])};
    if (it != mp.end()) {
      cout << it->second + 1 << ' ' << i + 1 << '\n';
      return 0;
    }
    mp[x - vec[i]] = i;
  }
  cout << "IMPOSSIBLE" << '\n';
}
