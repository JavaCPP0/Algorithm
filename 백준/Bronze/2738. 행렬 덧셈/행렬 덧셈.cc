#include <iostream>

using namespace std;

int main(void)
{
    int n=0,m=0;

    cin>>n;
    cin>>m;

    int A[n][m],B[n][m],C[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>B[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            C[i][j] = A[i][j] +B[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}