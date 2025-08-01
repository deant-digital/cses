#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n + 1);
  for (ll i{1}; i <= n; ++i) {
    ll x;
    cin >> x;
    vec[x] = i;
  }
  ll ans{1};
  for (ll i{2}; i <= n; ++i) {
    if (vec[i] < vec[i - 1]) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
