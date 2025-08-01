#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  multiset<ll> st;
  while (n-- > 0) {
    ll x;
    cin >> x;
    st.insert(x);
  }
  while (m-- > 0) {
    ll x;
    cin >> x;
    auto it{st.upper_bound(x)};
    if (it != st.begin()) {
      --it;
      cout << *it << '\n';
      st.erase(it);
    } else {
      cout << -1 << '\n';
    }
  }
}
