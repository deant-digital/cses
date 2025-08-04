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
  ll ans{LLONG_MAX};
  for (ll i{}; i < (1LL << n); ++i) {
    ll val1{};
    ll val2{};
    for (ll j{}; j < n; ++j) {
      if (((i >> j) & 1) == 1) {
        val1 += vec[j];
      } else {
        val2 += vec[j];
      }
    }
    ll diff{abs(val1 - val2)};
    ans = min(ans, diff);
  }
  cout << ans << '\n';
}
