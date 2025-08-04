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
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION" << '\n';
    return 0;
  }
  vector<ll> ans;
  ans.reserve(n);
  for (ll i{2}; i <= n; i += 2) {
    ans.push_back(i);
  }
  for (ll i{1}; i <= n; i += 2) {
    ans.push_back(i);
  }
  print_vec(ans);
}
