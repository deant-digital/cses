#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<array<ll, 2>> ans;

void solve(ll n, ll from, ll to, ll aux) {
  if (n == 0) {
    return;
  }
  solve(n - 1, from, aux, to);
  ans.push_back({from, to});
  solve(n - 1, aux, to, from);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ans.reserve(1LL << n);
  solve(n, 1, 3, 2);
  cout << ans.size() << '\n';
  for (auto [from, to] : ans) {
    cout << from << ' ' << to << '\n';
  }
}
