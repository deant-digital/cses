#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  map<ll, ll> mp;
  ++mp[0];
  ll ans{};
  ll sum{};
  while (n-- > 0) {
    ll x0;
    cin >> x0;
    sum += x0;
    ans += mp[sum - x];
    ++mp[sum];
  }
  cout << ans << '\n';
}
