#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        vector<int> factors;
        for (int j = 2; j <= num; j++) {
            if (isPrime(j) && num % j == 0) {
                factors.push_back(j);
                while (num % j == 0) {
                    num /= j;
                }
            }
        }
        if (num > 1) {
            factors.push_back(num);
        }

        for (int j = 0; j < factors.size(); j++) {
            if (k % factors[j] == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}