#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree {
  ll n;
  vector<ll> vec;

  segtree(ll n_) {
    n = n_ <= 1 ? 1 : 1LL << (64 - __builtin_clzll(n_ - 1));
    vec.assign(n * 2, LLONG_MAX);
  }

  void update(ll i, ll x) {
    i += n;
    vec[i] = x;
    for (i /= 2; i >= 1; i /= 2) {
      vec[i] = min(vec[i * 2], vec[i * 2 + 1]);
    }
  }

  ll query(ll l, ll r) {
    ll res{LLONG_MAX};
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        res = min(res, vec[l--]);
      }
      if (r % 2 == 1) {
        res = min(res, vec[--r]);
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q;
  cin >> n >> q;
  segtree st(n);
  for (ll i{}; i < n; ++i) {
    ll x;
    cin >> x;
    st.update(i, x);
  }
  while (q-- > 0) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll k, u;
      cin >> k >> u;
      --k;
      st.update(k, u);
    } else {
      ll a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << st.query(a, b + 1) << '\n';
    }
  }
}
