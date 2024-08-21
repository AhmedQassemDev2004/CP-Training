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

#define TESTS false

vector<int> primes(1001);
vector<bool> prime(1001);
void seive(int n) {

  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (prime[i])
      primes.push_back(i);
  }
}

auto solve(int tc) {
  int n, k;
  cin >> n >> k;

  int count = 0;
  for (int p = 2; p <= n; p++) {
    if (!prime[p])
      continue;
  }

  cout << (count >= k ? "YES\n" : "NO\n");
}

signed main() {
  FAST_IO
  seive(1001);
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