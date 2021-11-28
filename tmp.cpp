#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){

        int N;cin>>N;
        if(N==0) break;
        vector<int> A(N+1);
        for(int i=1;i<=N;i++){
            cin>>A[i];
        }
        long long ans=0;
        for(int x=1;x<N;x++){
            for(int i=x;i<=N;i++){
                if(A[i]==x){
                    if(i!=A[i]){
                        ans+=(i-x)+1;
                        sort(A.begin(),A.begin()+i);
                        for(int j=0;j<N+1;j++){
                            cout<<A[j]<<",";
                        }
                        cout<<endl;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}