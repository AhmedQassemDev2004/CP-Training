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

template <typename T> class Stack {
private:
  int max_size, size = 0;
  T *arr;
  int topIndex;

public:
  Stack(int n) {
    this->max_size = n;
    this->arr = new T[n];
    this->topIndex = -1;
  };

  T top() { return this->arr[topIndex]; }

  void push(T t) {
    this->arr[++this->topIndex] = t;
    size++;
  }

  T pop() {
    size--;
    return this->arr[this->topIndex--];
  }

  bool empty() { return this->size == 0; }
};

auto solve(int tc) {
  string s;
  cin >> s;

  Stack<char> st(s.length());
  for (char &c : s) {
    if (st.empty()) {
      st.push(c);
    } else if (c == st.top()) {
      st.pop();
    } else {
      st.push(c);
    }
  }

  if (st.empty())
    cout << "Yes";
  else
    cout << "No";
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
