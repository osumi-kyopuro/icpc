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
    vector<vector<ll>> c(3, vector<ll>(3));
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3;j++){
            cin >> c[i][j];
        }
    }
    ll sa1 = c[0][0] - c[1][0];
    ll sa2 = c[1][0] - c[2][0];
    ll sb1 = c[0][0] - c[0][1];
    ll sb2 = c[0][1] - c[0][2];
    for (ll i = 0; i < 3; i++)
    {
        if(c[i][0]-c[i][1]!=sb1){
            cout << "No" << endl;
            exit(0);
        }
        if (c[i][1] - c[i][2] != sb2)
        {
            cout << "No" << endl;
            exit(0);
        }
    }
    for (ll j = 0; j < 3; j++)
    {
        if (c[0][j] - c[1][j] != sa1)
        {
            cout << "No" << endl;
            exit(0);
        }
        if (c[1][j] - c[2][j] != sa2)
        {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
}