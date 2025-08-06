#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// best, sum
using node = array<ll, 2>;

struct segment_tree {
  ll n;
  vector<node> vec;

  node merge(const node& n1, const node& n2) {
    ll best{max(n1[0], n1[1] + n2[0])};
    ll sum{n1[1] + n2[1]};
    return {best, sum};
  }

  segment_tree(const vector<ll>& _vec) {
    n = _vec.size() == 1 ? 1 : 1LL << (64 - __builtin_clzll(_vec.size() - 1));
    vec.assign(n * 2, {});
    for (ll i{}; i < _vec.size(); ++i) {
      vec[i + n] = {max(_vec[i], 0LL), _vec[i]};
    }
    for (ll i{n - 1}; i >= 1; --i) {
      vec[i] = merge(vec[i * 2], vec[i * 2 + 1]);
    }
  }

  void update(ll i, ll x) {
    i += n;
    vec[i] = {max(x, 0LL), x};
    for (i /= 2; i >= 1; i /= 2) {
      vec[i] = merge(vec[i * 2], vec[i * 2 + 1]);
    }
  }

  ll query(ll l, ll r) {
    node res1{};
    node res2{};
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        res1 = merge(res1, vec[l++]);
      }
      if (r % 2 == 1) {
        res2 = merge(vec[--r], res2);
      }
    }
    return merge(res1, res2)[0];
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
  segment_tree st(vec);
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
      --a, --b;
      cout << st.query(a, b + 1) << '\n';
    }
  }
}
