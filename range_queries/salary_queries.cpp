#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q;
  cin >> n >> q;
  vector<ll> vec(n);
  multiset<ll> st;
  for (ll& x : vec) {
    cin >> x;
    st.insert(x);
  }
  while (q-- > 0) {
    char c;
    cin >> c;
    if (c == '!') {
      ll k, x;
      cin >> k >> x;
      --k;
      st.erase(st.find(vec[k]));
      vec[k] = x;
      st.insert(x);
    } else {
      ll a, b;
      cin >> a >> b;
      cout << distance(st.lower_bound(a), st.upper_bound(b)) << '\n';
    }
  }
}
