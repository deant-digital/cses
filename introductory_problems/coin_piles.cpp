#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t-- > 0) {
    ll a, b;
    cin >> a >> b;
    if ((a + b) % 3 != 0 || min(a, b) * 2 < max(a, b)) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
}
