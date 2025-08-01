#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<ll> prices(n);
  for (ll& price : prices) {
    cin >> price;
  }
  vector<ll> pages(n);
  for (ll& page : pages) {
    cin >> page;
  }
  vector<ll> dp(x + 1, LLONG_MIN);
  dp[0] = 0;
  for (ll i{}; i < n; ++i) {
    ll price{prices[i]};
    ll page{pages[i]};
    for (ll j{x}; j - price >= 0; --j) {
      dp[j] = max(dp[j], dp[j - price] + page);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
