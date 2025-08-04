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
  ll ans{};
  for (ll i{1}; i < n; ++i) {
    if (vec[i] < vec[i - 1]) {
      ans += vec[i - 1] - vec[i];
      vec[i] = vec[i - 1];
    }
  }
  cout << ans << '\n';
}
