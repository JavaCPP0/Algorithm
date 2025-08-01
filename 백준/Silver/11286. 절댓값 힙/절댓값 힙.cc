#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int  a, int b) {
        int abs1 = abs(a);
        int abs2 = abs(b);
        if (abs1 == abs2) {
            return a > b;
        }
        else {
            return abs1 > abs2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, Compare> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int request;
        cin >> request;

        if (request == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(request);
        }
    }

    return 0;
}
