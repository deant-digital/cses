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
  vector<ll> ans(n);
  vector<array<ll, 2>> stk;
  for (ll i{}; i < n; ++i) {
    ll x;
    cin >> x;
    while (!stk.empty() && stk.back()[0] >= x) {
      stk.pop_back();
    }
    if (stk.empty()) {
      ans[i] = 0;
    } else {
      ans[i] = stk.back()[1];
    }
    stk.push_back({x, i + 1});
  }
  print_vec(ans);
}
