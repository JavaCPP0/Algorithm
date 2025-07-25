#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n,0);
    vector<int> result(n,0);

    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s.push(0);
    // 스택에는 오큰수가 저장되지 않은 인덱스들이 들어간다.
    // 스택이 비어있지않고 들어오는값이 더 크다면 
    // 들어오는값이 오큰수이므로 "result[s.top()] = 들어오는 값" 이다.
    // 들어오는 값이 더 작다면 다음값을 push한다.
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            result[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        result[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}


