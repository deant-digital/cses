#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q;
  cin >> n >> q;
  vector<string> vec(n);
  for (auto& row : vec) {
    cin >> row;
  }
  vector mat(n, vector<ll>(n));
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < n; ++j) {
      mat[i][j] = vec[i][j] == '*' ? 1 : 0;
    }
  }
  vector prefix(n + 1, vector<ll>(n + 1));
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < n; ++j) {
      prefix[i + 1][j + 1] = mat[i][j];
      prefix[i + 1][j + 1] += prefix[i][j + 1];
      prefix[i + 1][j + 1] += prefix[i + 1][j];
      prefix[i + 1][j + 1] -= prefix[i][j];
    }
  }
  while (q-- > 0) {
    ll y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    ll ans{prefix[y2][x2]};
    ans -= prefix[y1 - 1][x2];
    ans -= prefix[y2][x1 - 1];
    ans += prefix[y1 - 1][x1 - 1];
    cout << ans << '\n';
  }
}
