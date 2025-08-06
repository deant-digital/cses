#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
  ll n;
  vector<ll> vec;

  segment_tree(ll _n) {
    n = _n == 1 ? 1 : 1LL << (64 - __builtin_clzll(_n - 1));
    vec.assign(n * 2, LLONG_MAX);
  }

  segment_tree(const vector<ll>& _vec) : segment_tree(_vec.size()) {
    copy(_vec.begin(), _vec.end(), vec.begin() + n);
    for (ll i{n - 1}; i >= 1; --i) {
      vec[i] = min(vec[i * 2], vec[i * 2 + 1]);
    }
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
        res = min(res, vec[l++]);
      }
      if (r % 2 == 1) {
        res = min(vec[--r], res);
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
  vector<ll> vec1(n);
  vector<ll> vec2(n);
  for (ll i{}; i < n; ++i) {
    vec1[i] = vec[i] - i;
    vec2[i] = vec[i] + i;
  }
  segment_tree st1(vec1);
  segment_tree st2(vec2);
  while (q-- > 0) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll k, x;
      cin >> k >> x;
      --k;
      st1.update(k, x - k);
      st2.update(k, x + k);
    } else {
      ll k;
      cin >> k;
      --k;
      cout << min(st1.query(0, k + 1) + k, st2.query(k, n) - k) << '\n';
    }
  }
}
