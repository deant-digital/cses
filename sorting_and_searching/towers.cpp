#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  multiset<ll> st;
  while (n-- > 0) {
    ll x;
    cin >> x;
    auto it{st.upper_bound(x)};
    if (it != st.end()) {
      st.erase(it);
    }
    st.insert(x);
  }
  cout << st.size() << '\n';
}
