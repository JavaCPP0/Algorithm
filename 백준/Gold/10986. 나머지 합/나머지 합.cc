#include <iostream>
#include <vector>

using namespace std;

//구간 합 문제
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    long answer = 0;

    cin >> N >> M;

    vector<long> S(N, 0);
    vector<long> C(M, 0);

    cin >> S[0];
    for (int i = 1; i < N; i++) {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    for (int j = 0; j < N; j++) {
        int remainder = S[j] % M;
        if (remainder == 0) {
            answer++;
        }
        C[remainder]++;
    }

    for (int k = 0; k < M; k++) {
        if (C[k] > 1) {
            answer = answer + (C[k] * (C[k] - 1) / 2);
        }
    }
    cout << answer << "\n";


    return 0;
}