#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree {
  ll n;
  vector<ll> vec;

  segtree(ll n_) {
    n = n_ <= 1 ? 1 : 1LL << (64 - __builtin_clzll(n_ - 1));
    vec.assign(n * 2, 0);
  }

  segtree(const vector<ll>& vec_) : segtree(vec_.size()) {
    copy(vec_.begin(), vec_.end(), vec.begin() + n);
    for (ll i{n - 1}; i >= 1; --i) {
      vec[i] = vec[i * 2] ^ vec[i * 2 + 1];
    }
  }

  void update(ll i, ll x) {
    i += n;
    vec[i] = x;
    for (i /= 2; i >= 1; i /= 2) {
      vec[i] = vec[i * 2] ^ vec[i * 2 + 1];
    }
  }

  ll query(ll l, ll r) {
    ll res{};
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        res ^= vec[l++];
      }
      if (r % 2 == 1) {
        res ^= vec[--r];
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
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  segtree st(vec);
  while (q-- > 0) {
    ll a, b;
    cin >> a >> b;
    --a;
    --b;
    cout << st.query(a, b + 1) << '\n';
  }
}
