#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n = 100;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (is_prime[i]) {
            for(int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int k = 0; k <= n; ++k) {
        if (is_prime[k]) cout << k << " ";
    }
    return 0;
}