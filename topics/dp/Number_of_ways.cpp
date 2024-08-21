#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define pii pair<int, int>
#define f first
#define s second

#define TESTS false

// recursion solution
int rec(int s, int e, vector<int> &dp) {
    if (s > e) return 0;
    if (s == e) return 1;


    if (dp[s] != -1) return dp[s];


    dp[s] = rec(s + 1, e, dp) + rec(s + 2, e, dp) + rec(s + 3, e, dp);
    return dp[s];
}


void solve(int tc) {
    int s, e;
    cin >> s >> e;

//    vector<int> dp(e + 1);
//    dp[s] = 1;
//
//    for (int i = s + 1; i <= e; i++) {
//        if (i >= s)
//            dp[i] += dp[i - 1];
//        if (i - 2 >= s)
//            dp[i] += dp[i - 2];
//        if (i - 3 >= s)
//            dp[i] += dp[i - 3];
//    }
//
//    cout << dp[e] << '\n';

    vector<int> dp(e + 1, -1);

    int res = rec(s, e, dp);

    cout << res;
}

int32_t main() {
    int t = 1;
#if TESTS
    cin >> t;
#endif
    while (t--) {
        solve(t);
    }
    return 0;
}
