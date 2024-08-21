#include <bits/stdc++.h>
#include <utility>

using namespace std;

set<int> divisors(int n) {
  set<int> res;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.insert(i);
      res.insert(n / i);
    }
  }

  return res;
}

multiset<int> prime_factors(int n) {
  multiset<int> factors;
  while (n % 2 == 0) {
    n /= 2;
    factors.insert(2);
  }

  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors.insert(i);
      n /= i;
    }
  }

  if (n > 2) {
    factors.insert(n);
  }

  return factors;
}

bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

vector<bool> seive(int n) {
  vector<bool> prime(n + 1, true);

  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }

  return prime;
}

/* int gcd(int a, int b) { */
/*   if (b > a) */
/*     swap(a, b); */
/**/
/*   if (b == 0) { */
/*     return a; */
/*   } */
/**/
/*   return gcd(a % b, b); */
/* } */

int gcd(int a, int b) {
  multiset<int> factors_a = prime_factors(a);
  multiset<int> factors_b = prime_factors(b);

  multiset<int> common_factors;

  // Find common factors
  for (int factor : factors_a) {
    auto it = factors_b.find(factor);
    if (it != factors_b.end()) {
      common_factors.insert(factor);
      factors_b.erase(it);
    }
  }

  int result = 1;
  for (int factor : common_factors) {
    result *= factor;
  }

  return result;
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int n;
  cin >> n;

  multiset<int> factors = prime_factors(n);
  for (auto it : factors) {
    cout << it << ' ';
  }
  return 0;
}
