#include <bits/stdc++.h>
using namespace std;

string to_binary(int n) {
  string s = "";

  while (n > 0) {
    if (n % 2 == 0)
      s.push_back('0');
    else
      s.push_back('1');

    n /= 2;
  }
  return s;
}

int main() {
  // NOTES
  // a^b = c then a^c=b, b^c=a
}