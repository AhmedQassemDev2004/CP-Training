#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

struct op {
  int l, r, d;
};

auto solve() {
  int n, m, k;
  cin >> n >> m >> k;

  int arr[n + 1];
  read_arr(arr, n);

  vector<op> q(m);
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--, r--;
    q[i].l = l, q[i].r = r, q[i].d = d;
  }

  vector<int> q_times(m, 0);
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    q_times[a] += 1;
    if (b + 1 < m)
      q_times[b + 1] -= 1;
  }

  for (int i = 1; i < m; ++i) {
    q_times[i] += q_times[i - 1];
  }

  vector<int> partial(n, 0);
  for (int i = 0; i < m; i++) {
    partial[q[i].l] += q[i].d * q_times[i];
    if (q[i].r + 1 < n)
      partial[q[i].r + 1] -= q[i].d * q_times[i];
  }

  for (int i = 1; i < n; i++) {
    partial[i] += partial[i - 1];
  }

  for (int i = 0; i < n; i++) {
    arr[i] += partial[i];
  }

  print_arr(arr, n);
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}
