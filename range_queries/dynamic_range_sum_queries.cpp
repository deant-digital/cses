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
    for (++i; i >= 1; i -= i & -i) {
      res += vec[i];
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  fenwick_tree ft(n);
  for (ll i{}; i < n; ++i) {
    cin >> vec[i];
    ft.update(i, vec[i]);
  }
  while (q-- > 0) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll k, u;
      cin >> k >> u;
      --k;
      ft.update(k, u - vec[k]);
      vec[k] = u;
    } else {
      ll a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << ft.query(b) - ft.query(a - 1) << '\n';
    }
  }
}
