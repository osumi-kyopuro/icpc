#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool flag=false;
    vector<int>a={3,2,1,4};
    for(int i=0;i<4;i++){
        if(a[i]==4){
            flag=true;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}