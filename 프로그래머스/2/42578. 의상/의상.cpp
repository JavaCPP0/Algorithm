#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //전체 갯수 + 얼굴 x 상의 x 하의 x 겉옷
    // 그냥 딕셔너리에 key:부위 value:갯수 하면 될듯
    int answer = 1;
    
    unordered_map<string, int> cnt;
    cnt.reserve(clothes.size());
    
    for (const vector<string>& name : clothes) {
        cnt[name[1]]++;
    }
    
    for (const auto& [key, value] : cnt) {
        answer += answer * value;
    }
    
    
    return answer-1;
}