#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort(a) sort(all(a))
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

bool perfect_square(int n) {
  int x = sqrt(n);
  return x * x == n;
}

map<int, int> prime_factors(int p) {
  map<int, int> factors;
  for (int i = 2; i * i <= p; i++) {
    while (p % i == 0) {
      factors[i]++;
      p /= i;
    }
  }
  if (p > 1) {
    factors[p]++;
  }
  return factors;
}

auto solve(int tc) {
  int n;
  cin >> n;

  vector<int> a(n);
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    zeros += a[i] == 0;
  }

  // NOTES
  // #1: 0 is perfect
  // #2: if the number of some prime factor in the two numbers is even
  // #3: If the two number are perfect the result is prefect
  // #4: If the two numbers are the same
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