#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001] = {false};
int count =0;
bool DFS(string start, vector<vector<string>> tickets,int count);
    
    
vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(),tickets.end());
    // 모든 경우의 수를 탐색해야 하므로 DFS
    // 항공권이지만 그려보면 결국 방향 그래프
    DFS("ICN",tickets,0);
    return answer;
}

bool DFS(string start, vector<vector<string>> tickets, int count){
    
    answer.push_back(start);
    
    if(count >= tickets.size()) return true;
    
    for(int i = 0;i<tickets.size();i++){
        if(!visited[i] && tickets[i][0] == start){
            visited[i] = true;
            
            if (DFS(tickets[i][1], tickets, count + 1)) return true;
            visited[i] = false;
            
        }
    }
    
    answer.pop_back();
    return false;
    
}