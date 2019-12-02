//same as bin_exponentiation.cpp except that every multiplication has
//been replaced by mod m as mod never interferes with multiplication

#include <iostream>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) {
            result = result * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return result;
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;
    
    cout << binpow(a, b, m);
    return 0;
}