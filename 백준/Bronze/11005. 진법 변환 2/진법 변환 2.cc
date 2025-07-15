#include <iostream>
using namespace std;

int main(void) {
    int n, b;
    cin >> n >> b;

    string result = "";
    while (n > 0) {
        int remainder = n % b;

        // 숫자 0~9는 '0'~'9', 10~35는 'A'~'Z'로 변환
        if (remainder < 10)
            result = char('0' + remainder) + result;
        else
            result = char('A' + (remainder - 10)) + result;

        n = n / b;
    }

    cout << result;
    return 0;
}
