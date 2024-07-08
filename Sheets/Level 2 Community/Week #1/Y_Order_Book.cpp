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

struct order {
  char direction;
  int price;
  int volume;
};

auto solve(int tc) {
  int n, s;
  cin >> n >> s;

  map<int, int> B, S;

  for (int i = 0; i < n; ++i) {
    char d;
    int p, q;
    cin >> d >> p >> q;
    if (d == 'B') {
      B[p] += q;
    } else {
      S[p] += q;
    }
  }

  vector<order> sortedS;
  for (auto it = S.rbegin(); it != S.rend(); ++it) {
    sortedS.push_back({'S', it->first, it->second});
  }

  vector<order> sortedB;
  for (auto it = B.rbegin(); it != B.rend(); ++it) {
    sortedB.push_back({'B', it->first, it->second});
  }

  int sellCount = 0;
  for (auto& order : sortedS) {
    if (sellCount >= s)
      break;
    cout << order.direction << " " << order.price << " " << order.volume << endl;
    sellCount++;
  }

  int buyCount = 0;
  for (auto& order : sortedB) {
    if (buyCount >= s)
      break;
    cout << order.direction << " " << order.price << " " << order.volume << endl;
    buyCount++;
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