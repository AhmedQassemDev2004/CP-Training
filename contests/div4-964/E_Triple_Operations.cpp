#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);

int min_operations(int l, int r) {
  vector<int> nums;
  for (int i = l; i <= r; i++) {
    nums.push_back(i);
  }

  int operations = 0;

  while (!nums.empty()) {
    sort(nums.begin(), nums.end(), greater<int>());

    int x = nums.back();
    nums.pop_back();

    if (nums.empty()) {
      if (x == 0)
        break;
      nums.push_back(3 * x);
    } else {
      int y = nums.back();
      nums.pop_back();
      if (x == 0 && y == 0)
        continue;
      nums.push_back(3 * x);
      nums.push_back(y / 3);
    }

    operations++;
  }

  return operations;
}

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << min_operations(l, r) << '\n';
  }
}

int main() {
  FAST_IO
  solve();
  return 0;
}
