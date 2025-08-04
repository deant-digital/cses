#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t-- > 0) {
    ll y, x;
    cin >> y >> x;
    ll mx{max(y, x)};
    if (mx % 2 == 0) {
      swap(y, x);
    }
    cout << mx * mx - ((y - 1) + (mx - x)) << '\n';
  }
}
