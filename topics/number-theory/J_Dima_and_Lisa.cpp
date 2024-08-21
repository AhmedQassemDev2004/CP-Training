#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define f first
#define s second

bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

auto solve() {
  int n;
  cin >> n;

  if (is_prime(n)) {
    cout << 1 << endl
         << n << endl;
  } else {
    cout << 3 << endl
         << 3 << " ";
    n -= 3;
    for (int i = 3; i < n; i += 2) {
      if (is_prime(i) && is_prime(n - i)) {
        cout << i << " " << n - i << endl;
        return;
      }
    }
  }
}

signed main() {
  FAST_IO
  solve();
  return 0;
}
