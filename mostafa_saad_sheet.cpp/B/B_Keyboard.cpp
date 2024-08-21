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
#define x first
#define y second

double dist(const pii& p1, const pii& p2) {
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

signed main() {
  FAST_IO

  int n, m, x;
  cin >> n >> m >> x;

  char a[n][m];
  map<char, vector<pii>> mp;
  vector<pii> shift;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      mp[a[i][j]].push_back(make_pair(i, j));
      if (a[i][j] == 'S') {
        shift.push_back(make_pair(i, j));
      }
    }
  }

  map<char, double> min_dist;

  for (auto& [ch, positions] : mp) {
    if (ch == 'S')
      continue;

    double _min = INT_MAX;

    for (auto& p : positions) {
      for (auto& s : shift) {
        _min = min(_min, dist(p, s));
      }
    }

    min_dist[ch] = _min;
  }

  int q;
  cin >> q;

  string t;
  cin >> t;

  int res = 0;
  bool possible = true;

  for (int i = 0; i < q; i++) {
    if (islower(t[i])) {
      if (mp.count(t[i]) == 0) {
        possible = false;
        break;
      }
    } else if (isupper(t[i])) {
      char c = tolower(t[i]);
      if (mp.count(c) == 0 || mp.count('S') == 0) {
        possible = false;
        break;
      }

      if (min_dist[c] > (double)x) {
        res++;
      }
    }
  }

  if (possible) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
