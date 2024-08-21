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
#define pci pair<char, int>
#define f first
#define s second

#define TESTS false

auto solve(int tc) {
  string strs[3];
  for (int i = 0; i < 3; i++) {
    cin >> strs[i];
  }

  map<char, int> mp = {
      {'A', 0},
      {'B', 0},
      {'C', 0},
  };

  for (string& s : strs) {
    if (s[1] == '>') {
      mp[s[0]]++;
    } else {
      mp[s[2]]++;
    }
  }

  vector<pci> vec(mp.begin(), mp.end());

  sort(all(vec), [](const pci& a, const pci& b) {
    return a.s < b.s;
  });

  if (mp['A'] == mp['B'] && mp['B'] == mp['C'] && mp['A'] == mp['C']) {
    cout << "Impossible\n";
  } else {
    for (auto [a, b] : vec) {
      cout << a;
    }
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