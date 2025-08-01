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
  ll x, n;
  cin >> x >> n;
  set<ll> lights;
  multiset<ll> lengths;
  lights.insert(0);
  lights.insert(x);
  lengths.insert(x);
  vector<ll> ans;
  ans.reserve(n);
  while (n-- > 0) {
    ll x0;
    cin >> x0;
    auto it{lights.upper_bound(x0)};
    auto it0{prev(it)};
    ll length{*it - *it0};
    lengths.erase(lengths.find(length));
    lengths.insert(*it - x0);
    lengths.insert(x0 - *it0);
    lights.insert(x0);
    ans.push_back(*lengths.rbegin());
  }
  print_vec(ans);
}
