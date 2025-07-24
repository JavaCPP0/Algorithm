#include <iostream>

using namespace std;

long long factorial(int a);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;

    long long result = factorial(n);

    cout << result;

    return 0;
}


long long factorial(int a) {
    if (a == 0) return 1;

    return a * factorial(a - 1);
}