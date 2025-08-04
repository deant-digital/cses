#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> vec1(n);
  vector<ll> vec2(m);
  for (ll& x : vec1) {
    cin >> x;
  }
  for (ll& x : vec2) {
    cin >> x;
  }
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  ll i{};
  ll j{};
  ll ans{};
  while (i < n && j < m) {
    if (vec1[i] + k < vec2[j]) {
      ++i;
    } else if (vec1[i] > vec2[j] + k) {
      ++j;
    } else {
      ++i;
      ++j;
      ++ans;
    }
  }
  cout << ans << '\n';
}
