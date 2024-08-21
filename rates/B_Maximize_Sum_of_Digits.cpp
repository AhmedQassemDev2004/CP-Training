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

int sum_digit(string n) {
  int sum = 0;
  for (char& c : n) {
    sum += c - '0';
  }

  return sum;
}

signed main() {
  FAST_IO

  string s;
  cin >> s;

  int n = s.length();

  int max = sum_digit(s);
  string ans = s;

  for (int i = n - 2; i >= 0; i--) {
    string tmp = s;
    int c = (tmp[i] - '0') - 1;
    tmp[i] = c + '0';
    for (int j = i + 1; j < n; j++) {
      tmp[j] = '9';
    }

    if (sum_digit(tmp) > max) {
      ans = tmp;
      max = sum_digit(tmp);
    }

    tmp = s;
  }

  int p = 0;
  for (p = 0; p < n; p++) {
    if (ans[p] != '0') {
      break;
    }
  }

  for (int i = p; i < n; i++) {
    cout << ans[i];
  }

  return 0;
}
