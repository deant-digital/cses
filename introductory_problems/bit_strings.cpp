#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod_exp(ll base, ll exp, ll mod) {
  ll val{1};
  while (exp > 0) {
    if (exp % 2 == 1) {
      val *= base;
      val %= mod;
    }
    base *= base;
    base %= mod;
    exp /= 2;
  }
  return val;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  cout << mod_exp(2, n, 1e9 + 7) << '\n';
}
