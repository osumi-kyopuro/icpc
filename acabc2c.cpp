#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;
int main() {
    vector<ll>x(3);
    vector<ll>y(3);
    vector<double>l(3,0);
    for(ll i=0;i<3;i++){
        cin>>x[i]>>y[i];    
    }
    ll k=0;
    bool flag=false;
    for(ll i=0;i<2;i++){
        for(ll j=i+1;j<3;j++){
            l[k]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            k++;
            if(i==1){
                flag=true;
            }
        }
        if(flag){
            break;
        }
    }
    double ms=0,s=0;
    for(ll i=0;i<3;i++){
        ms+=l[i];
    }
    ms/=2.0;
    s=sqrt(ms*(ms-l[0])*(ms-l[1])*(ms-l[2]));
    printf("%f\n",s);



    
}

