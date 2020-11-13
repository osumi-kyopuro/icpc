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
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;

int main()
{
    string s,ys;
    cin >> s;
    for (ll i = 0; i < s.size(); i++)
    {
        for (ll j = 0; j < s.size();j++){
            ys = s;
            ys.erase(i,j);
            //cout << ys << endl;
            if (ys == "keyence")
            {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    cout << "NO" << endl;
}
