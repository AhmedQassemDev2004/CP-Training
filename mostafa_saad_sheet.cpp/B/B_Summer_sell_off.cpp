#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define f first
#define s second

struct day {
  int a, b, g;
};

signed main() {
  FAST_IO

  int n, x;
  cin >> n >> x;

  vector<day> p(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i].a >> p[i].b;
    p[i].g = min(2 * p[i].a, p[i].b) - min(p[i].a, p[i].b);
  }

  sort(all(p), [&](day x1, day x2) {
    return x1.g > x2.g;
  });

  int res = 0;
  for (int i = 0; i < x; i++) {
    res += min(2 * p[i].a, p[i].b);
  }

  for (int i = x; i < n; i++) {
    res += min(p[i].a, p[i].b);
  }

  cout << res << endl;

  return 0;
}
