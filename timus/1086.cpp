#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int LIMIT = 200000;
bitset<LIMIT> is_prime;

int main() {
    vector<int> primes;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 3; i < LIMIT; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (1LL * i * i < LIMIT) {
                for (int j = i * i; j < LIMIT; j += i * 2) {
                    is_prime[j] = 0;
                }
            }
        }
        if (primes.size() >= 15000) break;
    }

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        cout << primes[n - 1] << '\n';
    }

    return 0;
}
