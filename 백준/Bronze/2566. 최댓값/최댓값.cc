#include <iostream>

using namespace std;

int main(void)
{
    int A[9][9];
    int max = -1;
    int x,y;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]>max){
                max = A[i][j];
                x=i+1;
                y=j+1;
            }
        }
    }

    cout<<max<<endl;
    cout<<x<<" "<<y;

    return 0;
}