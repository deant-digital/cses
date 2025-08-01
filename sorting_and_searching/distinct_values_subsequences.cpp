#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  sort(vec.begin(), vec.end());
  ll ans{1};
  ll cur{1};
  for (ll i{1}; i < n; ++i) {
    if (vec[i] == vec[i - 1]) {
      ++cur;
    } else {
      ans *= cur + 1;
      ans %= ll(1e9 + 7);
      cur = 1;
    }
  }
  ans *= cur + 1;
  ans %= ll(1e9 + 7);
  ans += ll(1e9 + 7) - 1;
  ans %= ll(1e9 + 7);
  cout << ans << '\n';
}
