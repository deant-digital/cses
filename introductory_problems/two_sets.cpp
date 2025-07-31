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
  ll sum{n * (n + 1) / 2};
  if (sum % 2 == 1) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  vector<ll> ans1, ans2;
  ans1.reserve(n);
  ans2.reserve(n);
  ll t{sum / 2};
  for (ll i{n}; i >= 1; --i) {
    if (t >= i) {
      t -= i;
      ans1.push_back(i);
    } else {
      ans2.push_back(i);
    }
  }
  cout << ans1.size() << '\n';
  print_vec(ans1);
  cout << ans2.size() << '\n';
  print_vec(ans2);
}
