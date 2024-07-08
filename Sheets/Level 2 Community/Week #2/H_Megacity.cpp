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
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

struct city {
  int x, y, k;
  double d;
};

double distance(double x, double y) {
  // distance = √((x2 – x1)² + (y2 – y1)²).
  // (x1, y1) is (0,0)
  // so distance = √(x2² + y2²).
  return sqrt(x * x + y * y);
}

bool cmp(city c1, city c2) {
  if (c1.d == c2.d)
    return c1.k > c2.k;
  return c1.d < c2.d;
}

auto solve(int tc) {
  int n, s;
  cin >> n >> s;

  vector<city> cities(n);
  int check = 0;
  for (int i = 0; i < n; i++) {
    int x, y, k;
    cin >> x >> y >> k;

    city c = {.x = x, .y = y, .k = k, .d = distance(x, y)};
    cities[i] = c;
    check += k;
  }

  if (check < 1e6 - s) {
    cout << -1;
    return;
  }

  sort(all(cities), cmp);

  double res = 0;
  int sum_k = 0;
  for (auto c : cities) {
    res = max(c.d, res);
    sum_k += c.k;

    if (sum_k >= 1e6 - s)
      break;
  }

  cout << setprecision(8) << res;
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
