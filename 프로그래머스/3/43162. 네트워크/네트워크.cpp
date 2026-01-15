#include <string>
#include <vector>

using namespace std;

vector<vector<int>> A; // 인접 리스트
vector<bool> visited;
void DFS(int node);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    A.resize(n+1);
    visited = vector<bool>(n+1,false);
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(i != j && computers[i][j] == 1) A[i+1].push_back(j+1);
        }
    }
    
    for(int i = 1; i<=n;i++){
        if(!visited[i]){
            answer++;
            DFS(i);
        }
    }
    
    return answer;
}

void DFS(int node){
    if(visited[node]) return;
    
    visited[node] = true;
    
    for(int num : A[node]){
        if(!visited[num]){
            DFS(num);
        }
    }
}

