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

auto solve(int tc) {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  max_heap(int) pq;
  min_heap(int) min_pq;

  for (auto x : a) {
    pq.push(x);
    min_pq.push(x);
  }

  int _max = 0, _min = 0, cnt = 0;
  while (!pq.empty() && cnt < n) {
    int x = pq.top();
    pq.pop();
    _max += x--;
    if (x >= 1) {
      pq.push(x);
    }

    cnt++;
  }

  cnt = 0;
  while (!min_pq.empty() && cnt < n) {
    int x = min_pq.top();
    min_pq.pop();
    _min += x--;

    if (x >= 1) {
      min_pq.push(x);
    }

    cnt++;
  }

  cout << _max << ' ' << _min;
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