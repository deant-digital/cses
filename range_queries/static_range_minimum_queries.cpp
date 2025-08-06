#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct sparse_table {
  vector<ll> lgs;
  vector<vector<ll>> vec;
  sparse_table(const vector<ll>& _vec) {
    ll n(_vec.size());
    lgs.resize(n + 1);
    for (ll i{2}; i <= n; ++i) {
      lgs[i] = lgs[i / 2] + 1;
    }
    ll lg{};
    while ((1LL << lg) <= n) {
      ++lg;
    }
    vec.resize(lg, vector<ll>(n));
    for (ll i{}; i < n; ++i) {
      vec[0][i] = _vec[i];
    }
    for (ll k{1}; k < lg; ++k) {
      for (ll i{}; i + (1LL << k) <= n; ++i) {
        vec[k][i] = min(vec[k - 1][i], vec[k - 1][i + (1LL << (k - 1))]);
      }
    }
  }
  ll query(ll l, ll r) {
    ll k = lgs[r - l];
    return min(vec[k][l], vec[k][r - (1LL << k)]);
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
  sparse_table st(vec);
  while (q-- > 0) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    cout << st.query(a, b + 1) << '\n';
  }
}
