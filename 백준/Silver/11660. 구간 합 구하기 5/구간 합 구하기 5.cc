#include <iostream>
#include <vector>
using namespace std;

//구간 합 문제
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, quiz;

    cin >> size >> quiz;

    //2차원 배열의 원본A, 구간합D를 0으로 초기화하여 사이즈보다 하나 크게 생성 => 구간합 공식을 위해 0으로 채워진 공간이 필요함
    vector<vector<int>> A(size+1, vector<int>(size+1,0));
    vector<vector<int>> D(size+1, vector<int>(size+1,0));

    //원본배열 받으면서 구간합배열 생성
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cin >> A[i][j];
            
            //구간합을 구하려는 위치 기준 위에거,왼쪽거 더하고 왼쪽대각선에 있는거 빼고 원본배열의 현위치값 더하기
            D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < quiz; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //x1,y1 ~ x2,y2사이의 구간합 구하는 공식
        int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
        cout << result << "\n";

    }

    return 0;
}