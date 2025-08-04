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
  ll ans{1};
  sort(vec.begin(), vec.end());
  for (ll x : vec) {
    if (ans < x) {
      break;
    }
    ans += x;
  }
  cout << ans << '\n';
}
