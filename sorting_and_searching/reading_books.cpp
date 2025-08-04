#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll sum{};
  ll mx{};
  while (n-- > 0) {
    ll x;
    cin >> x;
    sum += x;
    if (mx < x) {
      mx = x;
    }
  }
  cout << max(sum, mx * 2) << '\n';
}
