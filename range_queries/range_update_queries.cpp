#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  ll n;
  vector<ll> vec;

  fenwick_tree(ll n) : n(n), vec(n + 1) {}

  void update(ll i, ll x) {
    for (++i; i < n; i += i & -i) {
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
  fenwick_tree ft(n);
  for (ll i{}; i < n; ++i) {
    ll x;
    cin >> x;
    ft.update(i, x);
    ft.update(i + 1, -x);
  }
  while (q-- > 0) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll a, b, u;
      cin >> a >> b >> u;
      --a;
      --b;
      ft.update(a, u);
      ft.update(b + 1, -u);
    } else {
      ll k;
      cin >> k;
      --k;
      cout << ft.query(k) << '\n';
    }
  }
}
