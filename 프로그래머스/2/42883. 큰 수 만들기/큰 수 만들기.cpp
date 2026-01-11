#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> st;
    
    for(char c : number){
        while(k>0 && !st.empty() && st.top()<c){
            st.pop();
            k--;
        }
        st.push(c);
    }
    
    if(k>0){
        for(int i=0;i<k;i++){
            st.pop();
        }
    }
    
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}