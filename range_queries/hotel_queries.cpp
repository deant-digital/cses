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

struct segment_tree {
  ll n;
  vector<ll> vec;
  segment_tree(ll _n) {
    n = _n == 1 ? 1 : 1LL << (64 - __builtin_clzll(_n - 1));
    vec.assign(n * 2, LLONG_MIN);
  }
  segment_tree(const vector<ll>& _vec) : segment_tree(_vec.size()) {
    copy(_vec.begin(), _vec.end(), vec.begin() + n);
    for (ll i{n - 1}; i >= 1; --i) {
      vec[i] = max(vec[i * 2], vec[i * 2 + 1]);
    }
  }
  void update(ll i, ll x) {
    i += n;
    vec[i] = x;
    for (i /= 2; i >= 1; i /= 2) {
      vec[i] = max(vec[i * 2], vec[i * 2 + 1]);
    }
  }
  ll query(ll l, ll r) const {
    ll res{LLONG_MIN};
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        res = max(res, vec[l++]);
      }
      if (r % 2 == 1) {
        res = max(res, vec[--r]);
      }
    }
    return res;
  }
};

ll find_first_not_less_than(const segment_tree& st, ll x) {
  ll l{};
  ll r{st.n};
  while (l < r) {
    ll m{l + (r - l) / 2};
    if (st.query(0, m + 1) >= x) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> hs(n);
  for (ll& h : hs) {
    cin >> h;
  }
  segment_tree st(hs);
  vector<ll> ans;
  ans.reserve(m);
  while (m-- > 0) {
    ll r;
    cin >> r;
    ll res{find_first_not_less_than(st, r)};
    if (res >= n) {
      res = -1;
    } else {
      hs[res] -= r;
      st.update(res, hs[res]);
    }
    ans.push_back(res + 1);
  }
  print_vec(ans);
}
