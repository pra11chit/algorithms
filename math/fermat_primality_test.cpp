#include <iostream>
#include <cstdlib>
using namespace std;

long long binpower(long long a, long long b, int m) {
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

bool probablyprimefermat(int n, int iter) {

    if (n < 4) {
        return n == 2 || n == 3;
    }

    for (int i = 0; i < iter; ++i) {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int p, iter;
    cin >> p >> iter;
    cout << probablyprimefermat(p, iter);
    return 0;
}