#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<int> arr(str.size(),0);

    for (int i = 0; i < str.size(); i++) {
        arr[i] = stoi(str.substr(i,1));
    }

    for (int i = 0; i < str.size() ; i++) {
        int max = i;
        for (int j = 1 +i; j < str.size(); j++) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }

}