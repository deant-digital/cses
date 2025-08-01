#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<pair<ll, bool>> vec;
  vec.reserve(n * 2);
  while (n-- > 0) {
    ll a, b;
    cin >> a >> b;
    vec.push_back({a, false});
    vec.push_back({b, true});
  }
  sort(vec.begin(), vec.end());
  ll best{};
  ll current{};
  for (auto& [_, bl] : vec) {
    if (bl) {
      --current;
    } else {
      ++current;
      if (best < current) {
        best = current;
      }
    }
  }
  cout << best << '\n';
}
