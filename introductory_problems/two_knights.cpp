#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  for (ll i{1}; i <= n; ++i) {
    cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';
  }
}
