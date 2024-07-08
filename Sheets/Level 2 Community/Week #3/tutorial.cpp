#include <bits/stdc++.h>
using namespace std;

set<int> divisors(int n) {
  set<int> st;

  // NOTE: Remove one if unwanted
  st.insert(1);

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      st.insert(i);
      st.insert(n / i);
    }
  }

  return st;
}

map<int, int> prime_factors(int n) {
  map<int, int> res;

  while (n % 2 == 0) {
    res[2]++;
    n /= 2;
  }

  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }

  if (n > 2) {
    res[n]++;
    n /= n;
  }

  return res;
}

vector<bool> sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  return is_prime;
}

int gcd(int a, int b) {
  map<int, int> a_factors = prime_factors(a), b_factors = prime_factors(b);
  int res = 1;
  for (auto& factor : a_factors) {
    int prime = factor.first;
    if (b_factors.find(prime) != b_factors.end()) {
      int min_power = min(factor.second, b_factors[prime]);
      res *= pow(prime, min_power);
    }
  }
  return res;
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  return 0;
}