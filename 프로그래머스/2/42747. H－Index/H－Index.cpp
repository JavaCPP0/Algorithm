#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < (int)citations.size(); ++i) {
        int paperCount = i + 1;
        int citeCount  = citations[i];

        if (citeCount >= paperCount) {
            h = paperCount;
        } else {
            break;
        }
    }
    return h;
}
