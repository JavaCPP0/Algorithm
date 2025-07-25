#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //1부터 오름차순으로 n까지의 수를 스택에 넣고 빼면서 입력된 수열을 만들 수 있는지
    int n, i = 0;
    int num = 1;
    cin >> n;

    vector<int> arr(n);
    vector<char> result;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    for (int i = 0; i < n; i++) {
        if (arr[i] >= num) {
            while (arr[i] >= num) {
                s.push(num);
                num++;
                result.push_back('+');
            }
            s.pop();
            result.push_back('-');

        }
        else {
            int top = s.top();
            s.pop();
            if (top > arr[i]) {
                cout << "NO";
                return 0;
            }
            else {
                result.push_back('-');

            }
        }
    }

    if (result.size()) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "\n";
        }

    }

    return 0;
}


