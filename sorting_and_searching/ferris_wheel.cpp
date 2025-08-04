#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (ll& x0 : vec) {
    cin >> x0;
  }
  sort(vec.begin(), vec.end());
  ll i{};
  ll j{n - 1};
  ll ans{};
  while (i < j) {
    if (vec[i] + vec[j] <= x) {
      ++i;
    }
    --j;
    ++ans;
  }
  if (i == j) {
    ++ans;
  }
  cout << ans << '\n';
}
