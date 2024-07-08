#include <bits/stdc++.h>
using namespace std;

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
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n;
  cin >> n;

  stack<string> st;

  bool ok = true, start = true;
  int header_count = 0;
  while (n--) {
    string s;
    cin >> s;

    if (start && s != "Header") {
      cout << "WA";
      return;
    }

    if (s == "Header")
      header_count++;

    start = false;

    if (st.empty()) {
      st.push(s);
      continue;
    }

    if (s.find("End") == string::npos) {
      st.push(s);
    } else {
      if (s != ("End" + st.top())) {
        ok = false;
        break;
      }
      st.pop();
    }
  }

  if (ok && st.empty() && header_count == 1) {
    cout << "ACC";
  } else {
    cout << "WA";
  }
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }
#else
  solve(1);
#endif

  return 0;
}
