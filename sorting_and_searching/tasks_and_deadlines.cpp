#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans{};
  vector<ll> vec;
  vec.reserve(n);
  while (n-- > 0) {
    ll a, d;
    cin >> a >> d;
    ans += d;
    vec.push_back(a);
  }
  ll sum{};
  sort(vec.begin(), vec.end());
  for (ll x : vec) {
    sum += x;
    ans -= sum;
  }
  cout << ans << '\n';
}
