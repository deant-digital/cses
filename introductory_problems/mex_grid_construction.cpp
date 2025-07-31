#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
void print_vec(const vector<T>& vec) {
  if (!vec.empty()) {
    cout << vec[0];
  }
  for (ll i{1}; i < vec.size(); ++i) {
    cout << ' ' << vec[i];
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector ans(n, vector<ll>(n));
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < n; ++j) {
      ans[i][j] = i ^ j;
    }
  }
  for (auto& row : ans) {
    print_vec(row);
  }
}
