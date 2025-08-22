#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<int> answer;
    int minNum = 0;

    cin >> str;

    string token;
    stringstream ss(str);

    vector<string> parts;

    while (getline(ss, token, '-')) {
        parts.push_back(token);
    }

    for (string& p : parts) {
        stringstream ss2(p);
        string t;
        int sum = 0;

        while (getline(ss2, t, '+')) {
            sum += stoi(t); // 문자열을 정수로 변환
        }
        answer.push_back(sum);
    }

    minNum = answer[0];

    for (int i = 1; i < answer.size(); i++) {
        minNum -= answer[i];
    }


    cout << minNum;

    return 0;
}
