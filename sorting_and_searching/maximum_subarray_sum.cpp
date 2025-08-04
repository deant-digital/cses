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
  ll current{vec[0]};
  ll best{current};
  for (ll i{1}; i < n; ++i) {
    current = max(current + vec[i], vec[i]);
    best = max(best, current);
  }
  cout << best << '\n';
}
