#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; int L;
    cin >> N >> L;

    bool found = false;

    for (int l = L; l <= 100; l++) {
        int numerator = 2 * N - l * (l - 1); //분자
        int denominator = 2 * l;            //분모

        if (numerator % denominator == 0) {
            int a = numerator / denominator;
            if (a >= 0) { found = true;
            for (int i = 0; i < l; i++) {
                cout << a + i << " ";
            }
            break;
            }
        }
    }

    if (!found) {
        cout << "-1";
    }
    return 0;
}
