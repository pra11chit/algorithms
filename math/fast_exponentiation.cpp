#include <iostream>
using namespace std;

int fastexp (int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    int result = fastexp(a, b/2);
    if (b % 2 == 0) {
        return result  * result;
    }
    else {
        return result * result * a;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << fastexp(a, b);
    return 0;
}