#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  ll low{*max_element(vec.begin(), vec.end())};
  ll high{accumulate(vec.begin(), vec.end(), 0LL)};
  while (low < high) {
    ll mid{low + (high - low) / 2};
    ll cnt{1};
    ll sum{};
    for (ll x : vec) {
      if (sum + x <= mid) {
        sum += x;
      } else {
        sum = x;
        ++cnt;
        if (cnt > k) {
          break;
        }
      }
    }
    if (cnt <= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}
