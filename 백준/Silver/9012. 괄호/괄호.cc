#include<string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (char c : s) {
        if(c == '('){
            st.push(c);
        }else{
            if(st.empty()) return false;
            else st.pop();
        }
    }
    
    if(st.empty()) return true;

    return false;
}

int main(){
    int n;
    cin >> n;
    
    string str;
    for(int i =0;i<n;i++){
        cin >>str;
        if(solution(str)){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
    return 0;
}