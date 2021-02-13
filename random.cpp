string s;
bool is_answer(string &check){
  static const long double d10[]={
    1.6103079869623227,
    24.796654783692492,
    188.89013710938030,
    1230.2224494915222,
    7615.6253474497770,
    46263.959219420440,
    278976.51521468535,
    1677266.5750291492,
    10071941.934101876,
    60452082.302420020,
    362762534.46070680,
    2176697776.6721880
    };
  static const long double d90[]={
    9.2363568997811230,
    46.058788436836690,
    241.96619614654060,
    1360.6340223278112,
    7935.2311472107480,
    47046.897279040015,
    280894.34128440823,
    1681964.2814700499,
    10083448.922397340,
    60480268.554079200,
    362831576.39579240,
    2176866894.1843114
  };
  bool flag=true;
  long double d6=1;
  for(int d=1;d<=12;d++){
    map<string,int> s;
    for(int i=d;i<=N;i+=d){
      string tmp="";
      for(int j=i-d;j<i;j++){
        tmp+=check[j];
      }
      if(tmp.size()!=d){continue;}
      s[tmp]+=1;
    }
    d6*=6;
    long double sum=0.0;
    for(auto f:s){
      sum+=f.second*f.second;
    }
    long double kai_2=(d6/(int)(N/d))*sum-(int)(N/d);
    if(d10[d-1]<=kai_2&&kai_2<=d90[d-1]){}//制約条件を満たす
    else{
      flag=false;
    }
  }
  if(flag) cout<<"この乱数列は制約条件を満たします。"<<endl;
  else cout<<"この乱数列は制約条件を満たしません。"<<endl;
  return flag;
}


cin>>s;
if(bool is_answer(s)){
  cout<<s<<endl;
}
