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
#include <cstdio>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <cfenv>
#include <list>
#include<string.h>
#include <iterator>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rrep(i, s, n) for (ll i = (ll)(s); i > (ll)(n); i--)
#define all(a) (a).begin(), a.end()
#define rall(a) (a).rbegin(),(a).rend()
#define PI 3.14159265359
#define mod 1000000007
#define P pair<ll, ll>
#define V vector<ll>
#define C vector<char>
#define B vector<bool>
#define endl '\n'
const ll MAX = 510000;
const ll MOD =1000000007;
using namespace std;
using graph = vector<vector<ll>>;



//小数点12桁
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(6);
    }
} All_init;



int main() {
    string s="12345612345612345612345612345612345612345612345612";
    ll a,b;
    cin>>a>>b;
    swap(s[a-1],s[b-1]);
    cout<<s<<endl;
    
}