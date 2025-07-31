#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans{};
  while (n >= 5) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans << '\n';
}
