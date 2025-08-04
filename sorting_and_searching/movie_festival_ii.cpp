#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<array<ll, 2>> vec(n);
  for (auto& [b, a] : vec) {
    cin >> a >> b;
  }
  sort(vec.begin(), vec.end());
  multiset<ll> st;
  ll ans{};
  for (auto [b, a] : vec) {
    auto it{st.upper_bound(a)};
    if (it != st.begin()) {
      st.erase(--it);
    }
    if (st.size() < k) {
      st.insert(b);
      ++ans;
    }
  }
  cout << ans << '\n';
}
