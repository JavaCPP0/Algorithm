#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    
    for(int i = 0;i<n;i++){
        int up = name[i] -'A';
        int down = 'Z' - name[i] + 1;
        answer += min(up,down);
    }
    
    int move = n -1;
    
        for (int i = 0; i < n; i++) {
        int j = i + 1;

        while (j < n && name[j] == 'A') {
            j++;
        }

        int case1 = 2 * i + (n - j);
        int case2 = i + 2 * (n - j);

        move = min(move, min(case1, case2));
    }
    answer += move;
    return answer;
}