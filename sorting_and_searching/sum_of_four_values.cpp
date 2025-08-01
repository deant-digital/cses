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
  ll n, x;
  cin >> n >> x;
  vector<array<ll, 2>> vec(n);
  for (ll i{}; i < n; ++i) {
    auto& [x0, i0]{vec[i]};
    cin >> x0;
    i0 = i + 1;
  }
  sort(vec.begin(), vec.end());
  for (ll i{}; i < n; ++i) {
    for (ll j{i + 1}; j < n; ++j) {
      ll k{j + 1};
      ll l{n - 1};
      while (k < l) {
        ll sum{vec[i][0] + vec[j][0] + vec[k][0] + vec[l][0]};
        if (sum == x) {
          vector<ll> ans{vec[i][1], vec[j][1], vec[k][1], vec[l][1]};
          sort(ans.begin(), ans.end());
          print_vec(ans);
          return 0;
        }
        if (sum < x) {
          ++k;
        } else {
          --l;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}
