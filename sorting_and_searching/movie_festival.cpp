#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<array<ll, 2>> vec(n);
  for (auto& [b, a] : vec) {
    cin >> a >> b;
  }
  sort(vec.begin(), vec.end());
  ll ans{};
  ll last{};
  for (auto [b, a] : vec) {
    if (last <= a) {
      ++ans;
      last = b;
    }
  }
  cout << ans << '\n';
}
