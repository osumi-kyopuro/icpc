#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <tuple>
#define ll long long
using namespace std;
double factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

double dist(pair<int,int> a,pair<int,int> b){
	return sqrt(pow((a.first - b.first) ,2) + pow((a.second - b.second),2));
}

struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;


int main()
{
    ll n,n2=0;
    cin>>n;
    n2=n;
    vector<ll>a(n+1);
    vector<ll>b;
    for(ll i=1;i<n+1;i++){
        cin>>a[i];
    }
    bool flag=true;
    ll i=0;
    while(i!=n2){
        cout<<a[n]<<" ";
        if(flag){
            n-=2;
            if(n==0){
                n=1;
                flag=false;
            }
            else if(n==-1){
                n=2;
                flag=false;
            }
        }
        else{
            n+=2;
        }
        i++;
    }
    cout<<endl;
}
