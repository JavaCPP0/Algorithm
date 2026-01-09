#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


unordered_set<int> primeSet;
bool isPrime(int num);
void DFS(int number, const vector<int>& v, vector<bool>& used);

int solution(string numbers) {
    vector<int> v;
    
    for(char c : numbers){
        v.push_back(c-'0');
    }
    
    vector<bool> used(v.size(), false);

    for(int i = 0; i < (int)v.size(); i++){
        used[i] = true;
        DFS(v[i], v, used);
        used[i] = false;
    }

    return (int)primeSet.size();
}

void DFS(int number, const vector<int>& v, vector<bool>& used){
    if(isPrime(number)){
        primeSet.insert(number);
    }
    
    for(int i = 0; i < (int)v.size(); i++){
        if(used[i]) continue;
        
        used[i] = true;
        DFS(number*10 + v[i],v,used);
        used[i] = false;
        
    }

    
}



bool isPrime(int num){
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for(long long i = 3; i * i <= num; i += 2){
        if(num % i == 0) return false;
    }
    return true;
}
