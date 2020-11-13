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
    ll n,count=0,x=0;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%4==0){
            count++;
        }
        else if(a[i]%2==0){
            x++;
        }
    }
    count+=x/2;
    if(count>=n/2){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    
}
