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
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  ordered_set<ll> os;
  for (ll i{}; i < n; ++i) {
    os.insert(i);
  }
  vector<ll> ans;
  ans.reserve(n);
  while (n-- > 0) {
    ll x;
    cin >> x;
    --x;
    auto it = os.find_by_order(x);
    ans.push_back(vec[*it]);
    os.erase(it);
  }
  print_vec(ans);
}
