#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct bitree {
  ll n;
  vector<ll> vec;
  bitree(ll n) : n(n), vec(n + 1) {}
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  vector<ll> comps;
  comps.reserve(n);
  for (ll& x : vec) {
    cin >> x;
    comps.push_back(x);
  }
  sort(comps.begin(), comps.end());
  comps.erase(unique(comps.begin(), comps.end()), comps.end());
  bitree bit(comps.size());
  ll ans{};
  for (ll x : vec) {
    ll idx{lower_bound(comps.begin(), comps.end(), x) - comps.begin()};
    ll prefix{bit.query(idx - 1)};
    ll current{(prefix + 1) % ll(1e9 + 7)};
    bit.update(idx, current);
    ans += current;
    ans %= ll(1e9 + 7);
  }
  cout << ans << '\n';
}
