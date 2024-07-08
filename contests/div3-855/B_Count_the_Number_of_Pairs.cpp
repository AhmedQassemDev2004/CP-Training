#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
int next() {
    int x;
    cin >> x;
    return x;
}

string snext() {
    string s;
    cin >> s;
    return s;
}

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve(int tc) {
    int n = next(), k = next();
    string s = snext();

    map<char, pii > mp;
    for (char &c: s) {
        if (isupper(c)) {
            mp[tolower(c)].s++;
        } else {
            mp[tolower(c)].f++;
        }
    }

    int sum = 0;
    for (auto &[c, p]: mp) {
        int add = min(p.f, p.s);
        sum += add, p.f -= add, p.s -= add;

        add = min(k, max(p.f, p.s) / 2);
        sum += add, k -= add;
    }
    cout << sum << endl;
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