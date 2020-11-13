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
#define ll long long
using namespace std;

int main(){
    ll x;
    double n1, n2;
    cin >> x;
    n1= (-1 + sqrt(1 + 8 * x)) / 2.0;
    n2 = (-1 - sqrt(1 + 8 * x)) / 2.0;
    if(n2<0){
        n2 =1000000000;
    }
    if((ll)(n1)<n1){
        n1++;
    }
    if ((ll)(n2) < n2)
    {
        n2++;
    }
    cout << min((ll)(n1), (ll)(n2)) << endl;
    
}