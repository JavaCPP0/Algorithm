#include <iostream>
#include <vector>

using namespace std;

int push(vector<int>& s, int a) {
    s.push_back(a);
    return a;
}

int pop(vector<int>& s) {
    if (s.empty()) return -1;
    int temp = s.back();
    s.pop_back();
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> s; // 지역 변수로 스택 선언

    for (int i = 0; i < n; i++) {
        int order;
        cin >> order;

        switch (order)
        {
        case 1: {
            int x;
            cin >> x;
            push(s, x);
            break;
        }
        case 2:
            cout << pop(s) << "\n";
            break;
        case 3:
            cout << s.size() << "\n";
            break;
        case 4:
            cout << (s.empty() ? 1 : 0) << "\n";
            break;
        case 5:
            cout << (s.empty() ? -1 : s.back()) << "\n";
            break;
        }
    }
}
