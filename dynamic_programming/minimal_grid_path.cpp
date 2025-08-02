#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<string> mat(n);
  for (auto& row : mat) {
    cin >> row;
  }
  string ans(n * 2 - 1, 0);
  ans[0] = mat[0][0];
  vector<array<ll, 2>> vec{{0, 0}};
  for (ll i{1}; i < ans.size(); ++i) {
    vector<array<ll, 2>> tmp;
    tmp.reserve(vec.size() * 2);
    for (auto [a, b] : vec) {
      if (a + 1 < n) {
        tmp.push_back({a + 1, b});
      }
      if (b + 1 < n) {
        tmp.push_back({a, b + 1});
      }
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    char c{CHAR_MAX};
    for (auto [a, b] : tmp) {
      if (c > mat[a][b]) {
        c = mat[a][b];
      }
    }
    ans[i] = c;
    vector<array<ll, 2>> nxt;
    nxt.reserve(tmp.size());
    for (auto [a, b] : tmp) {
      if (mat[a][b] == c) {
        nxt.push_back({a, b});
      }
    }
    vec.swap(nxt);
  }
  cout << ans << '\n';
}
