#include <bits/stdc++.h>

void solve(int n, std::string str) {
  std::map<char, int> occur;
  char last = str[0];
  for (int i = 0; i < n; i++) {
    if (!occur[str[i]]) {
      occur[str[i]]++;
    } else if (occur[str[i]] && last != str[i]) {
      std::cout << "NO\n";
      return;
    }

    last = str[i];
  }

  std::cout << "YES\n";
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;
    solve(n, str);
  }
}
