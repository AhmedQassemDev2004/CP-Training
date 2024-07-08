#include <algorithm>
#include <bits/stdc++.h>
#include <experimental/filesystem>
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
#define read_set(st, n) for(int i=0;i<n;i++){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  string s;
  cin >> s;

  int n;
  cin >> n;

  unordered_map<char, int> char_order;
  for (int i = 0; i < s.size(); i++) {
    char_order[s[i]] = i;
  }

  auto cmp = [&](string a, string b) {
    int len1 = a.length(), len2 = b.length();
    for (int i = 0; i < min(len1, len2); ++i) {
      if (char_order[a[i]] < char_order[b[i]])
        return true;
      if (char_order[a[i]] > char_order[b[i]])
        return false;
    }
    return len1 > len2;
  };

  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    strs.push_back(str);
  }

  sort(all(strs), cmp);

  int k;
  cin >> k;

  cout << strs[k - 1];
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
