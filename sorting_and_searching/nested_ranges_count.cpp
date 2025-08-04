#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  ll n;
  vector<ll> vec;

  fenwick_tree(ll n) : n(n), vec(n + 1) {}

  void update(ll i, ll x) {
    for (++i; i <= n; i += i & -i) {
      vec[i] += x;
    }
  }

  ll query(ll i) {
    ll res{};
    for (++i; i > 0; i -= i & -i) {
      res += vec[i];
    }
    return res;
  }
};

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
  vector<array<ll, 3>> vec(n);
  map<ll, ll> mp;
  for (ll i{}; i < n; ++i) {
    auto& [a, b, i0]{vec[i]};
    cin >> a >> b;
    i0 = i;
    mp[b] = 0;
  }
  ll i0{};
  for (auto& [key, value] : mp) {
    value = i0++;
  }
  vector<ll> ans1(n);
  vector<ll> ans2(n);
  fenwick_tree ft1(i0);
  fenwick_tree ft2(i0);
  sort(vec.begin(), vec.end(),
       [](const array<ll, 3>& a, const array<ll, 3>& b) -> bool {
         if (a[0] != b[0]) {
           return a[0] > b[0];
         }
         return a[1] < b[1];
       });
  for (auto [a, b, i] : vec) {
    ll idx{mp[b]};
    ans1[i] = ft1.query(idx);
    ft1.update(idx, 1);
  }
  reverse(vec.begin(), vec.end());
  for (auto [a, b, i] : vec) {
    ll idx{mp[b]};
    ans2[i] = ft2.query(i0 - 1) - ft2.query(idx - 1);
    ft2.update(idx, 1);
  }
  print_vec(ans1);
  print_vec(ans2);
}
