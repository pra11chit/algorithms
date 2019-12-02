#include <vector>
#include <iostream>
using namespace std;

vector<int> primes;

void primefactor (int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            primes.push_back(i);
        }
    }

    if (n > 1)
        primes.push_back(n);

    for(int i = 0; i < primes.size(); ++i) {
        cout << primes[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    primefactor(n);
    return 0;
}