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
    ll n,k=0;
    double sum=0;
    cin>>n;
    vector<pair<ll,ll>>xy(n);
    for(ll i=0;i<n;i++){
        cin>>xy[i].first>>xy[i].second;
    }
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        a[i]=i;
    }
    do{
        for(ll i=0;i<n-1;i++){
            sum+=dist(xy[a[i]],xy[a[i+1]]);
        }
        k++;

    }while(next_permutation(a.begin(),a.end()));
    double ans=sum/k;
    cout<<ans<<endl;

}
