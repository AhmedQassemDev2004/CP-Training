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
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define f first
#define s second
// clang-format on

#define TESTS false

bool cmp(pii a, pii b) {
  return a.s < b.s;
}

auto solve(int tc) {
  int n;
  cin >> n;

  map<int, int> occur = {
      {1, 0},
      {2, 0},
      {3, 0}};

  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].s;
    a[i].f = i + 1;
    occur[a[i].s]++;
  }

  int min_occur = INT_MAX, prev = 0;
  for (auto [p, x] : occur) {
    min_occur = min(x, min_occur);
  }

  if (min_occur == 0) {
    cout << 0;
    return;
  }

  sort(all(a), cmp);

  //   for (auto it : a) {
  //     cout << it.s << ' ';
  //   }
  //   cout << '\n';

  map<int, bool> done; // {index, done}
  vector<vector<int>> teams(min_occur, vector<int>());
  for (int i = 0; i < min_occur; i++) {
    int current = 1;
    for (int j = 0; j < n; j++) {
      if (!done[a[j].f] && a[j].s == current) {
        teams[i].push_back(a[j].f);
        done[a[j].f] = true;
        current++;
      }

      if (current == 4) {
        break;
      }
    }
  }

  cout << teams.size() << '\n';
  for (auto team : teams) {
    for (auto i : team) {
      cout << i << ' ';
    }

    cout << '\n';
  }
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