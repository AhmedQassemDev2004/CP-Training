#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

#define TESTS true

vector<int> prime_factors(int n) {
  vector<int> factors;

  while (n % 2 == 0) {
    factors.push_back(2);
    n /= 2;
  }

  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }

  if (n > 2) {
    factors.push_back(n);
  }

  return factors;
}

bool is_binary_decimal(int num) {
  while (num > 0) {
    int digit = num % 10;
    if (digit != 0 && digit != 1) {
      return false;
    }
    num /= 10;
  }
  return true;
}

auto solve(int tc) {
  int n;
  cin >> n;

  vector<int> factors = prime_factors(n);

  for (int i = 0; i < factors.size(); i++) {
    if (!is_binary_decimal(factors[i])) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }
#else
  solve(1);
#endif

  return 0;
}