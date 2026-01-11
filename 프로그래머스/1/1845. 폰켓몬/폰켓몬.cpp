#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    int n = nums.size()/2;
    
    for(int num : nums){
        s.insert(num);
    }
    
    if(s.size() >= n) return n;
    
    return s.size();
}