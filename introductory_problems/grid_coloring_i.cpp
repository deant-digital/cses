#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> mat, ans;
bool is_possible(ll x, ll y) {
  if (ans[x][y] == mat[x][y]) {
    return false;
  }
  if (x > 0 && ans[x][y] == ans[x - 1][y]) {
    return false;
  }
  if (y > 0 && ans[x][y] == ans[x][y - 1]) {
    return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  mat.resize(n);
  for (auto& row : mat) {
    cin >> row;
  }
  ans.assign(n, string(m, 0));
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < m; ++j) {
      if ((i + j) % 2 == 0) {
        ans[i][j] = 'A';
        if (is_possible(i, j)) {
          continue;
        }
        ans[i][j] = 'B';
      } else {
        ans[i][j] = 'C';
        if (is_possible(i, j)) {
          continue;
        }
        ans[i][j] = 'D';
      }
    }
  }
  for (auto& row : ans) {
    cout << row << '\n';
  }
}
