#include <queue>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> p;
    queue<int> s;

    for (int x : progresses) p.push(x);
    for (int x : speeds) s.push(x);

    int days = 0;

    while (!p.empty()) {
        int curp = p.front();
        int curs = s.front();
        int count = 0;
        int done = curp + curs * days;
        
        if (done < 100) {
            int remain = 100 - done;
            int addDays = (remain + curs - 1) / curs;
            days += addDays;
        }

        
        while (!p.empty()) {
            int pp = p.front();
            int ss = s.front();

            if (pp + ss * days >= 100) {
                p.pop();
                s.pop();
                count++;
            } else {
                break;
            }
        }

        answer.push_back(count);
    }

    return answer;
}
