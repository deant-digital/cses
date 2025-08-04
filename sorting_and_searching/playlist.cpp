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
  set<ll> st;
  ll best{};
  for (ll i{}, j{}; i < n; ++i) {
    auto it{st.find(vec[i])};
    if (it != st.end()) {
      do {
        st.erase(vec[j]);
      } while (vec[j++] != vec[i]);
    }
    st.insert(vec[i]);
    best = max(best, i - j + 1);
  }
  cout << best << '\n';
}
