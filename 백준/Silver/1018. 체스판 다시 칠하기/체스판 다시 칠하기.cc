#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    int N, M, answer = 64;
    cin >> N >> M;

    // 보드 전체 저장
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // (x, y)를 왼쪽 위로 하는 8x8 구간을 전부 검사
    for (int x = 0; x + 7 < N; x++) {
        for (int y = 0; y + 7 < M; y++) {

            int repaintW = 0; // (x,y)가 'W'로 시작하는 체스판으로 만들 때 필요한 칠하기 수
            int repaintB = 0; // (x,y)가 'B'로 시작하는 체스판으로 만들 때 필요한 칠하기 수

            // 8x8 내부 체크
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    char actual = board[x + i][y + j]; // 실제 보드 색

                    // (i + j)가 짝수면 시작색, 홀수면 반대색
                    // 시작색을 W라고 가정한 경우
                    if ((i + j) % 2 == 0) {
                        if (actual != 'W') repaintW++;  // 여기서는 W여야 하는데 아니면 repaintW++
                        if (actual != 'B') repaintB++;  // B로 시작한다고 가정하면 여기서는 B여야 함
                    }
                    else {
                        if (actual != 'B') repaintW++;  // W로 시작 시 홀수는 B여야 함
                        if (actual != 'W') repaintB++;  // B로 시작 시 홀수는 W여야 함
                    }
                }
            }

            int localMin = min(repaintW, repaintB);; // 이 8x8에서 필요한 최소 칠하기 수
            answer = min(answer, localMin);
        }
    }

    cout << answer;
    return 0;
}