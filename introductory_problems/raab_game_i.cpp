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
  ll t;
  cin >> t;
  while (t-- > 0) {
    ll n, a, b;
    cin >> n >> a >> b;
    if ((a + b) > n || (a == 0 && b > 0) || (b == 0 && a > 0)) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<ll> ans1(n);
    vector<ll> ans2(n);
    iota(ans1.begin(), ans1.end(), 1);
    for (ll i{}; i < b; ++i) {
      ans2[i] = a + i + 1;
    }
    for (ll i{b}; i < a + b; ++i) {
      ans2[i] = i - b + 1;
    }
    for (ll i{a + b}; i < n; ++i) {
      ans2[i] = i + 1;
    }
    print_vec(ans1);
    print_vec(ans2);
  }
}
