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
  map<ll, ll> mp;
  ll ans{};
  for (ll i{}, j{}; i < n; ++i) {
    auto it{mp.find(vec[i])};
    if (it != mp.end() && it->second >= j) {
      j = it->second + 1;
    }
    mp[vec[i]] = i;
    ans += i - j + 1;
  }
  cout << ans << '\n';
}
