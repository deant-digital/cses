#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, t;
  cin >> n >> t;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  ll low{1};
  ll high{*min_element(vec.begin(), vec.end()) * t};
  while (low < high) {
    ll mid{low + (high - low) / 2};
    ll cnt{};
    for (ll x : vec) {
      cnt += mid / x;
    }
    if (cnt >= t) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}
