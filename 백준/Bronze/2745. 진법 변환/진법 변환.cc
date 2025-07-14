#include <iostream>
using namespace std;

int main(void) {
    string b;
    int n, result = 0;

    cin >> b >> n; // 입력 순서 고침

    for (int i = 0; i < b.length(); i++) {
        char ch = b[i];
        int digit;

        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (ch >= 'A' && ch <= 'Z')
            digit = ch - 'A' + 10;

        result = result * n + digit;
    }

    cout << result;
    return 0;
}
