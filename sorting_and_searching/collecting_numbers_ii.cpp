#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n + 1), vec0(n + 1);
  for (ll i{1}; i <= n; ++i) {
    ll x;
    cin >> x;
    vec[x] = i;
    vec0[i] = x;
  }
  ll ans{1};
  for (ll i{2}; i <= n; ++i) {
    if (vec[i] < vec[i - 1]) {
      ++ans;
    }
  }
  while (m-- > 0) {
    ll a, b;
    cin >> a >> b;
    vector<ll> tmp{vec0[a], vec0[a] + 1, vec0[b], vec0[b] + 1};
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (ll x : tmp) {
      if (x <= n && vec[x] < vec[x - 1]) {
        --ans;
      }
    }
    swap(vec0[a], vec0[b]);
    swap(vec[vec0[a]], vec[vec0[b]]);
    for (ll x : tmp) {
      if (x <= n && vec[x] < vec[x - 1]) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
}
