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
    if(s.size()==2){
        cout << 1 << endl;
        exit(0);
    }
    s.erase(s.size() - 2,2);
    while(s.size()>0){
        string sa = s.substr(0, s.size() / 2);
        string sb = s.substr(s.size() / 2, s.size() / 2);
        if(sa==sb){
            cout << s.size() << endl;
            exit(0);
        }
        s.erase(s.size()-2,2);
    }

}
