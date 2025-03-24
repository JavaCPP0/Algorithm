#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int max = 0;  // 최대 길이 초기화
    char A[5][15];
    string word;
    string answer;

    // 5개의 단어 입력 받기
    for (int i = 0; i < 5; i++)
    {
        cin >> word;
        if (word.length() > max)
        {
            max = word.length();  // 가장 긴 단어의 길이 구하기
        }
        // 각 단어를 15칸 배열에 저장, 남은 자리는 '\0'으로 채움
        for (int j = 0; j < 15; j++)
        {
            if (j < word.length())
            {
                A[i][j] = word[j];  // 단어가 길이가 작은 경우 그 부분만 복사
            }
            else
            {
                A[i][j] = '\0';  // 남은 자리는 null 문자로 채움
            }
        }
    }

    // 세로로 읽어서 answer에 저장
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (A[j][i] != '\0')  // 널 문자가 아닌 문자만 answer에 추가
            {
                answer += A[j][i];
            }
        }
    }

    // 결과 출력
    cout << answer;

    return 0;
}
