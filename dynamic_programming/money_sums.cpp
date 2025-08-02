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
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  set<ll> st{0};
  for (ll x : vec) {
    set<ll> nxt{st};
    for (ll x0 : st) {
      nxt.insert(x + x0);
    }
    st.swap(nxt);
  }
  vector<ll> ans(next(st.begin()), st.end());
  cout << ans.size() << '\n';
  print_vec(ans);
}
