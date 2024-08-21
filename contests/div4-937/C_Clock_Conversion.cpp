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

vector<string> get_hour(string s) {
  string hour, mins;
  bool flag = false;
  for (char c : s) {
    if (c == ':') {
      flag = true;
      continue;
    }
    if (!flag) {
      hour += c;
    } else {
      mins += c;
    }
  }

  return vector<string>{hour, mins};
}

auto solve(int tc) {
  string s;
  cin >> s;

  vector<string> res = get_hour(s);
  int hour = stoi(res[0]);

  string time = "AM";
  if (hour >= 12)
    time = "PM";

  if (hour != 12)
    hour %= 12;

  if (hour == 0)
    hour = 12;

  if (hour < 10)
    cout << '0';
  cout << hour << ':' << res[1] << ' ' << time << '\n';
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