#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec;
  vec.reserve(n);
  while (n-- > 0) {
    ll x;
    cin >> x;
    auto it{lower_bound(vec.begin(), vec.end(), x)};
    if (it != vec.end()) {
      *it = x;
    } else {
      vec.push_back(x);
    }
  }
  cout << vec.size() << '\n';
}
