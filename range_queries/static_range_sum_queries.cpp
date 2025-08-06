#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  vector<ll> prefix(n + 1);
  for (ll i{}; i < n; ++i) {
    prefix[i + 1] = prefix[i] + vec[i];
  }
  while (q-- > 0) {
    ll a, b;
    cin >> a >> b;
    cout << prefix[b] - prefix[a - 1] << '\n';
  }
}
