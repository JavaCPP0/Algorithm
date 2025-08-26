#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long limit = (long long) sqrtl(b);

    vector<char> isPrime(limit + 1, true);

    for (long long i = 2; i * i <= limit; ++i) {
        if (!isPrime[i]) continue;
        for (long long j = i * i; j <= limit; j += i) {
            isPrime[j] = false;
        }
    }

    long long count = 0;

    for (long long p = 2; p <= limit; ++p) {
        if (!isPrime[p]) continue;

        long long cur = p * p;
        while (cur <= b) {
            if (cur >= a) ++count;

            if (cur > b / p) break;
            cur *= p;
        }
    }

    cout << count << '\n';
    return 0;
}
