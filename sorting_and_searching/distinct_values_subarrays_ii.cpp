#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  map<ll, ll> mp;
  ll ans{};
  for (ll i{}, j{}; i < n; ++i) {
    ++mp[vec[i]];
    while (mp.size() > k) {
      auto it{mp.find(vec[j])};
      --it->second;
      if (it->second == 0) {
        mp.erase(it);
      }
      ++j;
    }
    ans += i - j + 1;
  }
  cout << ans << '\n';
}
