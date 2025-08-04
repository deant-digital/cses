#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n - 1);
  for (ll& x : vec) {
    cin >> x;
  }
  ll ans{};
  for (ll x : vec) {
    ans ^= x;
  }
  for (ll i{1}; i <= n; ++i) {
    ans ^= i;
  }
  cout << ans << '\n';
}
