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

string s;
string t;
vector<double> f(15,0);
void f1(){
    double p=0;
    t=s;
    vector<double> c(10,0);
    rep(j,0,t.size()){
        c[t[j]-'0']++;
    }
    rep(j,0,10){
        p+=c[j]*c[j];
    }
    f[0]=p*6/t.size()-t.size(); 
}

void f2(){
    double p=0;
    vector<double> c(10,0);
    t=s.substr(0,30*s.size()/100-0);
    rep(j,0,t.size()){
        c[t[j]-'0']++;
    }
    rep(j,0,10){
        p+=c[j]*c[j];
    }
    f[1]=p*6/t.size()-t.size(); 
}

void f3(){
    double p=0;
    vector<double> c(10,0);
    t=s.substr(23*s.size()/100,53*s.size()/100-23*s.size()/100);
    rep(j,0,t.size()){
        c[t[j]-'0']++;
    }
    rep(j,0,10){
        p+=c[j]*c[j];
    }
    f[2]=p*6/t.size()-t.size(); 
}

void f4(){
    double p=0;
    vector<double> c(10,0);
    t=s.substr(47*s.size()/100,77*s.size()/100-47*s.size()/100);
    rep(j,0,t.size()){
        c[t[j]-'0']++;
    }
    rep(j,0,10){
        p+=c[j]*c[j];
    }
    f[3]=p*6/t.size()-t.size();
    
}

void f5(){
    double p=0;
    vector<double> c(10,0);
    t=s.substr(70*s.size()/100,s.size()-70*s.size()/100);
    rep(j,0,t.size()){
        c[t[j]-'0']++;
    }
    rep(j,0,10){
        p+=c[j]*c[j];
    }
    f[4]=p*6/t.size()-t.size();
}

void f6(){
    ll t=0;
    rep(i,0,s.size()){
        if(s[i]%2!=s[i+1]%2){
            t++;
        }
    }
    f[5]=t;
}

void f7(){
    ll t=0;
    rep(i,0,s.size()-1){
        if(s[i]==s[i+1]){
            t++;
        }
    }
    f[6]=t;
}

void f8(){
    ll t=0;
    rep(i,0,s.size()-2){
        if(s[i]==s[i+1]&&s[i]==s[i+2]&&s[i+2]==s[i+1]){
            t++;
        }
    }
    f[7]=t;
}

void f9(){
    ll t=0;
    rep(i,0,s.size()-3){
        if(s[i]==s[i+1]&&s[i]==s[i+2]&&s[i]==s[i+3]
        &&s[i+1]==s[i+2]&&s[i+1]==s[i+3]&&s[i+2]==s[i+3]){
            t++;
        }
    }
    f[8]=t;
}

void f10(){
    ll cnt=0;
    rep(i,0,s.size()-3){
        string t=s.substr(i,4);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(x[0]==2&&x[1]==2){
            cnt++;
        }
    }
    f[9]=cnt;
}

void f11(){
    ll cnt=0;
    rep(i,0,s.size()-4){
        string t=s.substr(i,5);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(x[0]==3&&x[1]==2){
            cnt++;
        }
    }
    f[10]=cnt;
}

void f12(){
    ll cnt=0;
    rep(i,0,s.size()-3){
        string t=s.substr(i,4);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(t[0]==t[3]&&x[0]==3){
            cnt++;
        }
    }
    f[11]=cnt;

}

void f13(){
    ll cnt=0;
    rep(i,0,s.size()-4){
        string t=s.substr(i,5);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(t[0]==t[4]&&x[0]==3){
            cnt++;
        }
    }
    f[12]=cnt;
}

void f14(){
    ll cnt=0;
    rep(i,0,s.size()-5){
        string t=s.substr(i,6);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(t[0]==t[5]&&x[0]==4){
            cnt++;
        }
    }
    f[13]=cnt;
}

void f15(){
    ll cnt=0;
    rep(i,0,s.size()-6){
        string t=s.substr(i,7);
        vector<ll>x(10,0);
        rep(j,0,t.size()){
            x[t[j]-'0']++;
        }
        sort(rall(x));
        if(t[0]==t[6]&&x[0]==4){
            cnt++;
        }
    }
    f[14]=cnt;
}









int main() {
    cin>>s;
    f1(),f2(),f3(),f4(),f5(),f6(),f7(),f8(),f9(),f10(),f11(),f12(),f13(),f14(),f15();
    rep(i,0,15){
        if(i<5){
            cout<<"F"<<i+1<<"="<<f[i]<<endl;
        }
        else{
            cout<<"F"<<i+1<<"="<<(ll)(f[i])<<endl;
        }
    }
    

}