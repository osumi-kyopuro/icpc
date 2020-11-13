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
#include<limits>
#define ll long long
using namespace std;
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;

int main()
{
    ll h,h2,count,ans=0;
    cin>>h;
    vector<ll> a;
    ll t = 1;
    ll o = 2;
    while(t<h){
        t += o;
        o *= 2;
    }
    cout << t << endl;
}
