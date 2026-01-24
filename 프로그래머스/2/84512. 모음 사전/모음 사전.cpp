#include <string>
#include <vector>

using namespace std;

string vowels = "AEIOU";
int cnt = 0;
int answer = 0;

void dfs(string cur, const string& target) {
    // 빈 문자열은 사전에 포함되지 않으므로, cur이 비어있지 않을 때만 카운트
    if (!cur.empty()) {
        cnt++;
        if (cur == target) {
            answer = cnt;
            return;
        }
    }

    // 길이 5 제한
    if (cur.size() == 5) return;

    // 사전순: A -> E -> I -> O -> U 순으로 확장
    for (char c : vowels) {
        dfs(cur + c, target);
    }
}

int solution(string word) {
    cnt = 0;
    answer = 0;
    dfs("", word);
    return answer;
}
