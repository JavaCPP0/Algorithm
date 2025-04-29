#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int dataCnt,quizCnt;
    int arr[100001]={};
    
    cin>>dataCnt>>quizCnt;
    
    for(int i=1;i<=dataCnt;i++){
        int temp;
        cin>>temp;
        arr[i]=arr[i-1]+temp;
    }
    
    for(int i=0;i<quizCnt;i++){
        int start, end;
        cin>>start>>end;
        cout<<arr[end]-arr[start-1]<<"\n";
    }
    
    
    return 0;
}