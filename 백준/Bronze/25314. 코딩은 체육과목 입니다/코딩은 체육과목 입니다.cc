#include <iostream>

using namespace std;

int main(void){
    int byte = 0;
    cin>>byte;
    
    for(int i =0;i<byte/4;i++){
        cout<<"long ";
    }
    cout<<"int";
}