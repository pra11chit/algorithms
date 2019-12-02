#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

void simpleSieve(int limit, vector<int> &prime, int m) {
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));
    mark[0] = mark[1] = false;

    for (int p = 2; p*p < limit; ++p) {
        if (mark[p] == true ) {
            for (int i = p*p; i < limit; i += p) {
                mark[i] = false;
            }
        }
    }

    for(int p = 2; p < limit; ++p) {
        if (mark[p] == true ) {
            prime.push_back(p);       
        }

        if (mark[p] == true && p >= m) {
        cout << p << endl;
        }
    }

    
}

void segmentedSieve(long long int m, long long int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime, m);

    int low, high;
    if (limit >= m) {
        low = limit;
        high = 2*limit;
    }
    else {
        low = m;
        high = m + limit;
    }
    
    while (low < n) {
        if (high >= n) {
            high = n + 1;
        }

        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));

        for (int i = 0; i < prime.size(); ++i) {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low) {
                loLim += prime[i];
            }

            for (int j = loLim; j < high; j += prime[i]) {
                mark[j - low] = false;
            }
        }

        for (int i = low; i  < high; ++i) {
            if (mark[i - low] == true) {
                cout << i << endl;
            }
        }

        low = low + limit;
        high = high + limit;
    }
}

int main() {
    int T; 
    cin >> T;
    for (int a = T; a > 0; --a) {
        long long int M, N;
        cin >> M >> N;
        segmentedSieve(M, N);
    }
    return 0;
}