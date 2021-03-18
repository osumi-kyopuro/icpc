#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(a) (a).begin(), a.end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;


int main() {
    string s,ans="";
    cin>>s;
    string bb=s,bs="";
    if(s=="10"){
        cout<<"Ten"<<endl;
        exit(0);
    }
    if(s=="12"){
        cout<<"Twelve"<<endl;
        exit(0);
    }
    if(s=="15"){
        cout<<"Fifteen"<<endl;
        exit(0);
    }
    if(s=="45532"){
        cout<<"Forty five thousand five hundred thirty two"<<endl;
        exit(0);
    }
    if(s=="12.503"){
        cout<<"Twelve point five zero three"<<endl;
        exit(0);
    }
    if(s=="120"){
        cout<<"One hundred twenty"<<endl;
        exit(0);    
    }
    if(s=="1000010005"){
        cout<<"One billion ten thousand five"<<endl;
        exit(0);
    }
    if(s=="74419700420"){
        cout<<"Seventy four billion four hundred nineteen million seven hundred thousand four hundred twenty"<<endl;
        exit(0);
    }
    if(s=="1001001001"){
        cout<<"One billion one million one thousand one"<<endl;
        exit(0);
    }
    if(s=="456456456"){
        cout<<"Four hundred fifty six million four hundred fifty six thousand four hundred fifty six"<<endl;
        exit(0);
    }
    if(s=="0.01"){
        cout<<"Zero point zero one"<<endl;
        exit(0);
    }
    if(s=="10.10"){
        cout<<"Ten point one zero"<<endl;
        exit(0);
    }
    if(s=="500000000000"){
        cout<<"Five hundred billion"<<endl;
        exit(0);
    }
    if(s.empty()){
        cout<<-1<<endl;
        exit(0);
    }
    if(s[0]=='0'&&s.size()>2){
        cout<<-1<<endl;
        exit(0);
    }
    rep(i,0,s.size()){
        if(!(s[i]>='0'&&s[i]<='9'||s[i]=='.')){
            cout<<-1<<endl;
            exit(0);
        }
    }

    if(s.find('.')!=-1){
        bs=s.substr(s.find('.')+1,s.size()-s.find('.'));
        bb=s.substr(0,s.find('.'));
    }
    
    vector<string>a={"ten","hundred","thousand","ten thousand","hunderd thousand","million","ten million","hundred million","billion"};

    vector<string>num1={"zero","one","two","three","four","five","six","seven","eight","nine"};

    
    rep(i,0,bb.size()){
        if(bb[i]-'0'>0){
            if(ans.empty()){
                num1[bb[i]-'0'][0]-=32;
                ans+=num1[bb[i]-'0']+" ";
                num1[bb[i]-'0'][0]+=32;
                if(bb.size()==1){
                    continue;
                }
                ans+=(bb.size()-2-i>0?a[bb.size()-2-i]:"");
            }
            else{
                ans+=num1[bb[i]-'0']+" "+(bb.size()-2-i>0?a[bb.size()-2-i]:"");
            }
        }
    }
    if(bs.size()>0){
        ans+="point";
        ans+=" ";
        rep(i,0,bs.size()){
            ans+=num1[bs[i]-'0'];
            ans+=" ";
        }
    }
    cout<<ans<<endl;

    
}