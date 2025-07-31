#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fast_exp(ll base, ll exp) {
  ll val{1};
  while (exp > 0) {
    if (exp % 2 == 1) {
      val *= base;
    }
    base *= base;
    exp /= 2;
  }
  return val;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll q;
  cin >> q;
  while (q-- > 0) {
    ll k;
    cin >> k;
    --k;
    ll digits{1};
    while (k >= 9 * digits * fast_exp(10, digits - 1)) {
      k -= 9 * digits * fast_exp(10, digits - 1);
      ++digits;
    }
    ll first{fast_exp(10, digits - 1)};
    cout << to_string(first + k / digits)[k % digits] << '\n';
  }
}
