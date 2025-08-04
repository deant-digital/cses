#include <bits/stdc++.h>

using namespace std;
using ll = long long;

array<string, 8> mat{};
array<bool, 8> cols{};
array<bool, 15> diag1{};
array<bool, 15> diag2{};

ll solve(ll row) {
  if (row == 8) {
    return 1;
  }
  ll res{};
  for (ll col{}; col < 8; ++col) {
    if (mat[row][col] == '*') {
      continue;
    }
    if (cols[col] || diag1[row + col] || diag2[row + (7 - col)]) {
      continue;
    }
    cols[col] = diag1[row + col] = diag2[row + (7 - col)] = true;
    res += solve(row + 1);
    cols[col] = diag1[row + col] = diag2[row + (7 - col)] = false;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (auto& row : mat) {
    cin >> row;
  }
  cout << solve(0) << '\n';
}
