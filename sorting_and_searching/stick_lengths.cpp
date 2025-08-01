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
  ll median{vec[n / 2]};
  ll sum{};
  for (ll x : vec) {
    sum += abs(x - median);
  }
  cout << sum << '\n';
}
