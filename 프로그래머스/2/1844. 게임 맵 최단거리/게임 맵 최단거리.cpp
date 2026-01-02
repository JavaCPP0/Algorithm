#include<vector>
#include<queue>
using namespace std;

bool visited[100][100] = {false};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void BFS(int i,int j,vector<vector<int>>& maps,int n,int m);

int solution(vector<vector<int>> maps)
{
 
    int n = maps.size();
    int m = maps[0].size();
    
    BFS(0,0,maps,n,m);
    
    if(!visited[n-1][m-1]) return -1;
    return maps[n-1][m-1];
}

void BFS(int i,int j,vector<vector<int>>& maps,int n,int m){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    
    while(!q.empty()){
        int now[2];
        now[0] = q.front().first;
        now[1] = q.front().second;
        q.pop();
        visited[now[0]][now[1]] = true;
        for(int k=0;k<4;k++){
            int x = now[0] + dx[k];
            int y = now[1] + dy[k];
            
            if(x>=0 && y>=0 && x<n && y<m){
                if(maps[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    maps[x][y] = maps[now[0]][now[1]] + 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
}
