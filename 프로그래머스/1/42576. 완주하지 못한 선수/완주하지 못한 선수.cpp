#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;

    for (const string& name : completion) {
        cnt[name]++;
    }

    for (const string& name : participant) {
        auto it = cnt.find(name);
        if (it != cnt.end() && it->second > 0) {
            it->second--;
        } else {
            return name;
        }
    }

    return "";
}
