#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
void print_vec(const vector<T>& vec) {
  if (!vec.empty()) {
    cout << vec[0];
  }
  for (ll i{1}; i < vec.size(); ++i) {
    cout << ' ' << vec[i];
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<array<ll, 3>> vec(n);
  for (ll i{}; i < n; ++i) {
    auto& [a, b, i0]{vec[i]};
    cin >> a >> b;
    i0 = i;
  }
  sort(vec.begin(), vec.end());
  multiset<array<ll, 2>> st;
  ll tot{};
  vector<ll> ans(n);
  for (auto [a, b, i] : vec) {
    auto it{st.lower_bound({a, 0})};
    if (it == st.begin()) {
      ans[i] = ++tot;
      st.insert({b, tot});
    } else {
      --it;
      ans[i] = (*it)[1];
      st.erase(it);
      st.insert({b, ans[i]});
    }
  }
  cout << tot << '\n';
  print_vec(ans);
}
