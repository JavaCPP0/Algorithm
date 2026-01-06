#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    
    string answer = "";
    vector<string> s;
    s.reserve(numbers.size());

    for (int x : numbers) {
        s.push_back(to_string(x));
    }

    sort(s.begin(), s.end(), [](const string& a,const string& b){
        return a+b>b+a;
    });
    
    if(s[0] == "0" ) return "0";
    
    for(string str : s){
        answer += str;
    }
    
    return answer;
}

