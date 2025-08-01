#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  map<ll, ll> mp;
  ++mp[0];
  ll ans{};
  ll sum{};
  for (ll i{}; i < n; ++i) {
    ll x0;
    cin >> x0;
    sum += x0;
    ll key{(sum % n + n) % n};
    auto it{mp.find(key)};
    if (it == mp.end()) {
      it = mp.insert({key, 0}).first;
    }
    ans += it->second;
    ++it->second;
  }
  cout << ans << '\n';
}
