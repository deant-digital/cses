#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  ll n, k;
  cin >> n >> k;
  ordered_set<ll> st;
  for (ll i{1}; i <= n; ++i) {
    st.insert(i);
  }
  ll i{};
  vector<ll> ans;
  ans.reserve(n);
  while (n > 0) {
    i += k;
    i %= n;
    auto it{st.find_by_order(i)};
    ans.push_back(*it);
    st.erase(it);
    --n;
  }
  print_vec(ans);
}
