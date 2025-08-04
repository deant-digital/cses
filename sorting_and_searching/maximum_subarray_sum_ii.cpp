#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  vector<ll> prefix(n + 1);
  for (ll i{}; i < n; ++i) {
    prefix[i + 1] = prefix[i] + vec[i];
  }
  multiset<ll> st;
  ll ans{LLONG_MIN};
  for (ll i{a}; i <= n; ++i) {
    st.insert(prefix[i - a]);
    ans = max(ans, prefix[i] - *st.begin());
    if (i >= b) {
      st.erase(st.find(prefix[i - b]));
    }
  }
  cout << ans << '\n';
}
