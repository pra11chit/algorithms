//similar to fast exponentiation except that it uses iterative 
//call rather than recursive
#include <iostream>
using namespace std;

long long binpow(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) {
            result = result * a;
        }
        a = a * a;
        b >>= 1;
    }
    return result;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << binpow(a, b);
    return 0;
}