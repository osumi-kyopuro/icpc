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
    string s;
    cin >> s;
    vector<ll> a(26, 0);
    for (ll i = 0; i < s.size();i++){
        a[s[i]-'a']++;
    }
    for (ll i = 0; i < 26; i++)
    {
        if (a[i] <= 0)
        {
            cout << (char)('a' + i) << endl;
            exit(0);
        }
    }
    cout << "None" << endl;
}
