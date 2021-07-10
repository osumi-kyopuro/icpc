#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define endl '\n'
using namespace std;

int main() {
    string c;
    cin>>c;
    string s,ans,ks;
    cin>>s;
    bool flag=true;
    vector<string>ps;
    if(c=="compress"){
        ks=string(1,s[0]);
        rep(i,1,s.size()){
            if(s[i-1]!=s[i]){
                if(flag){
                    ks+=string(1,s[i]);
                    continue;
                }
                if(ks.size()>0){
                    ps.push_back(ks);       
                }
                flag=true;
                ks=string(1,s[i]);
            }
            else{
                if(flag){
                    ks.erase(ks.size()-1,1);
                    if(ks.size()>0){
                        ps.push_back(ks);    
                    }
                    ks=string(2,s[i]);
                }
                else{
                    ks+=string(1,s[i]);
                }
                flag=false;
            }
        }
        ps.push_back(ks);
        rep(i,0,ps.size()){
            if(ps[i][0]!=ps[i][1]){
                ans+=string(1,'-');
                ans+=to_string(ps[i].size());
                ans+=ps[i];
            }
            else{
                ans+=to_string(ps[i].size());
                ans+=ps[i][0];
            }
        }
    }
    else{
        ks=string(1,s[0]);
        rep(i,1,s.size()){
            if((s[i]=='-')||(s[i]>='0'&&s[i]<='9')){
                if(!flag){
                    ps.push_back(ks);
                    ks="";
                }
                ks+=string(1,s[i]);
                flag=true;
            }
            else{
                flag=false;
                ks+=string(1,s[i]);
            }
        }
        ps.push_back(ks);

        rep(i,0,ps.size()){
            if(ps[i][0]=='-'){
                rep(j,0,ps[i].size()){
                    if(ps[i][j]>='A'&&ps[i][j]<='z'){
                        ans+=string(1,ps[i][j]);
                    }
                }
            }
            else{
                string cnt;
                rep(j,0,ps[i].size()){
                    if(ps[i][j]>='0'&&ps[i][j]<='9'){
                        cnt+=string(1,ps[i][j]);
                    }
                    else{
                        ans+=string(stoll(cnt),ps[i][j]);
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}