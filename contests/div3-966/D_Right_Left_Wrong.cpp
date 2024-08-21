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
#define max_heap std::priority_queue<int>
#define min_heap std::priority_queue<int, std::vector<int>, std::greater<int>>

auto solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  string s;
  cin >> s;

  max_heap r;
  min_heap l;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      r.push(i);
    } else {
      l.push(i);
    }
  }

  vector<int> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix[i] += prefix[i - 1] + a[i];
  }

  int sum = 0;
  while (!l.empty() && !r.empty()) {
    int start = l.top(), end = r.top();
    if (start > end)
      break;

    l.pop(), r.pop();

    sum += (start > 0 ? prefix[end] - prefix[start - 1] : prefix[end]);
  }

  cout << sum << endl;
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}