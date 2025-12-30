#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < (int)phone_book.size() - 1; i++) {
        const string& a = phone_book[i];
        const string& b = phone_book[i + 1];

        if (b.find(a) == 0) {
            return false;
        }
    }
    return true;
}
