#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <array>
#include <random>
#include <iomanip>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int N;
const int M=7;
int SUBMIT_PROBLEM_NUMBER;//提出番号(--match=?)
//                           1  2  3  4  5   6    7  8   9  10   11  12  13   14   15
const long double ALPHA[15]={2, 2, 2, 2, 2, 27,   5, 1,  1,  1,   1,  1,  1,    1,   1};
const long double BETA [15]={5, 5, 5, 5, 5, 30,  18, 3, 10,  4,  12,  6,  8,   10,   2};
const long double GAMMA[15]={3, 3, 3, 3, 3,  1, 1.5, 3,  8,  4,   6,  4,  4,    4,   4};

long double Alpha[15];
long double Beta[15];
long double Gamma[15];

const string DIR_NAME="eccomp2020/";//フォルダ名
string OLD_ANSWER_FEATURE_DATA;//過去の提出結果
const string INPUT_FILE="M"+to_string(M)+".txt";//NとSUBMIT_PROBLEM_NUMBERが入っている.txtファイル

//プロトタイプ宣言
template <class T>
void show_vector(const vector<T> &t);
template<typename T>
void load();
void write_alpha_beta_gamma();
long double scoring_known(const long double &f);
string make_find_gamma_answer();
vector<string> make_find_alpha_beta_answer(const long double gamma,const pair<long double,long double> &mid);
bool is_answer(const string &check);
long double F1(const string &solution);
long double F2(const string &solution);
long double F3(const string &solution);
long double F4(const string &solution);
long double F5(const string &solution);
int F6(const string &solution);
int F7(const string &solution);
int F8(const string &solution);
int F9(const string &solution);
int F10(const string &solution);
int F11(const string &solution);
int F12(const string &solution);
int F13(const string &solution);
int F14(const string &solution);
int F15(const string &solution);
vector<vector<long double>> all_function(const vector<string> &solution);
pair<long double,long double> find_midPoint(const long double small_feature,const long double small_objective,const long double large_feature,const long double large_objective,const long double gamma);
vector<vector<long double>> scoring(const vector<vector<long double>> &F);

std::random_device mt;
std::uniform_int_distribution<std::size_t> random_1to6(1,6);

string execute(std::string cmd) {
  std::string file_name = "result.json";
  std::system((cmd + " > " + file_name).c_str()); // redirect output to file

  //open file for input, return string containing characters in the file
  std::ifstream file(file_name);
  return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

template<typename T>
string send_answer(const T &x) {
  string res;
    json j = x;
    string cmd = "echo '" + j.dump() + "' | opt submit --match=" + to_string(SUBMIT_PROBLEM_NUMBER);
    string s=execute(cmd);
    res=s;
    cout<<s<<endl;
  return res;
}

vector<vector<long double>> scoring(const vector<vector<long double>> &F){
  vector<vector<long double>> res(F.size());
  for(int it=0;it<F.size();it++){
    vector<long double> E(15);
    for(int i=0;i<15;i++){
      if(F[it][i]<ALPHA[i]){
        E[i]=GAMMA[i]*(ALPHA[i]-F[it][i]);
      }
      else if(F[it][i]>BETA[i]){
        E[i]=GAMMA[i]*(F[it][i]-BETA[i]);
      }
      else{
        E[i]=0;
      }
    }

    if(M==2){
      vector<long double> tmp(2,0.0);
      for(int i=0;i< 7;i++) tmp[0]+=E[i];
      for(int i=7;i<15;i++) tmp[1]+=E[i];

      res[it]=tmp;
    }
    else if(M==3){
      vector<long double> tmp(3,0.0);

      for(int i= 0;i< 5;i++) tmp[0]+=E[i];
      for(int i= 5;i<10;i++) tmp[1]+=E[i];
      for(int i=10;i<15;i++) tmp[2]+=E[i];

      res[it]=tmp;
    }
    else if(M==5){
      vector<long double> tmp(5,0.0);

      for(int i= 0;i< 3;i++) tmp[0]+=E[i];
      for(int i= 3;i< 6;i++) tmp[1]+=E[i];
      for(int i= 6;i< 9;i++) tmp[2]+=E[i];
      for(int i= 9;i<12;i++) tmp[3]+=E[i];
      for(int i=12;i<15;i++) tmp[4]+=E[i];

      res[it]=tmp;
    }
    else if(M==7){
      vector<long double> tmp(7,0.0);
      for(int i= 0;i< 2;i++) tmp[0]+=E[i];
      for(int i= 2;i< 4;i++) tmp[1]+=E[i];
      for(int i= 4;i< 6;i++) tmp[2]+=E[i];
      for(int i= 6;i< 8;i++) tmp[3]+=E[i];
      for(int i= 8;i<10;i++) tmp[4]+=E[i];
      for(int i=10;i<12;i++) tmp[5]+=E[i];
      for(int i=12;i<15;i++) tmp[6]+=E[i];

      res[it]=tmp;
    }

  }

  return res;
}

template<class T>
void show_vector(const vector<T> &t){
  /*
  if(t.size()!=15){

    cout<<"[";
    for(int i=0;i<t.size();i++){
      if(i!=0) cout<<", ";
      cout<<t[i];
    }
    cout<<"]"<<endl;

  }
  else{

    cout<<"[";
    if(M==2){}
    else if(M==3){}
    else if(M==5){}
    else if(M==7){
      cout<<" [";
      for(int i=0;i<15;i++){
        if((i&1)||(i==14)) cout<<",";
        if((i%2==0)&&(i!=14)&&(i!=0)) cout<<"] [";

        cout<<t[i];
      }
      cout<<"] ";
    }

    cout<<"]"<<endl;

  }
  */
}


void load(){
  /*
  ifstream Cin;
  Cin.open(INPUT_FILE);
  Cin>>N;
  Cin>>SUBMIT_PROBLEM_NUMBER;

  for(int i=0;i<15;i++){
    Cin>>Alpha[i];
  }
  for(int i=0;i<15;i++){
    Cin>>Beta[i];
  }
  for(int i=0;i<15;i++){
    Cin>>Gamma[i];
  }

  Cin.close();
  OLD_ANSWER_FEATURE_DATA=DIR_NAME+to_string(SUBMIT_PROBLEM_NUMBER)+".txt";
  cout<<OLD_ANSWER_FEATURE_DATA<<"を参照します"<<endl;
  */
}

void write_alpha_beta_gamma(){
  ofstream Cout(INPUT_FILE);


  Cout<<N<<endl;
  Cout<<SUBMIT_PROBLEM_NUMBER<<endl;

  for(int i=0;i<15;i++){
    if(i!=0) Cout<<" ";
    Cout<<Alpha[i];
  }
  Cout<<endl;
  for(int i=0;i<15;i++){
    if(i!=0) Cout<<" ";
    Cout<<Beta[i];
  }
  Cout<<endl;
  for(int i=0;i<15;i++){
    if(i!=0) Cout<<" ";
    Cout<<Gamma[i];
  }
  Cout<<endl;

  Cout.close();
}

//制約条件を満たすかどうか
bool is_answer(const string &check){
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

//特徴量
long double F1(const string &solution){
  long double res=0.0;
  long double sum=0.0;
  vector<int> tmp(6);
  for(int i=0;i<N;i++){
    tmp[solution[i]-'1']++;
  }
  for(int i=0;i<6;i++){
    sum+=tmp[i]*tmp[i];
  }
  res=(6.0/N)*sum-N;
  return res;
}
long double F2(const string &solution){
  long double res=0.0;
  long double sum=0.0;
  vector<int> tmp(6);
  int count=0;
  for(int i=0;i<30*N/100;i++){
    tmp[solution[i]-'1']++;
    count++;
  }
  for(int i=0;i<6;i++){
    sum+=tmp[i]*tmp[i];
  }
  res=(6.0/count)*sum - count;
  return res;
}
long double F3(const string &solution){
  long double res=0.0;
  long double sum=0.0;
  vector<int> tmp(6);
  int count=0;
  for(int i=23*N/100;i<53*N/100;i++){
    tmp[solution[i]-'1']++;
    count++;
  }
  for(int i=0;i<6;i++){
    sum+=tmp[i]*tmp[i];
  }
  
  res=(6.0/count)*sum - count;
  return res; 
}
long double F4(const string &solution){
  long double res=0.0;
  long double sum=0.0;
  vector<int> tmp(6);
  int count=0;
  for(int i=47*N/100;i<77*N/100;i++){
    tmp[solution[i]-'1']++;
    count++;
  }
  for(int i=0;i<6;i++){
    sum+=tmp[i]*tmp[i];
  }
  
  res=(6.0/count)*sum - count;
  return res; 
}
long double F5(const string &solution){
  long double res=0.0;
  long double sum=0.0;
  vector<int> tmp(6);
  int count=0;
  for(int i=70*N/100;i<N;i++){
    tmp[solution[i]-'1']++;
    count++;
  }
  for(int i=0;i<6;i++){
    sum+=tmp[i]*tmp[i];
  }
  
  res=(6.0/count)*sum - count;
  return res;
}
int F6(const string &solution){
    int res=0;
    for(int i=1;i<N;i++){
      if( (((solution[i-1]-'0')%2))^(((solution[i]-'0')%2)) ){
        res++;
      }
    }
    return res;
}
int F7(const string &solution){
  int res=0;
  for(int i=1;i<N;i++){
    if(solution[i]==solution[i-1]){
      res++;
    }
  }
  return res;
}
int F8(const string &solution){
  int res=0;
  for(int i=2;i<N;i++){
    if( (solution[i]==solution[i-1]) && (solution[i-1]==solution[i-2]) ){
      res++;
    }
  }
  return res;
}
int F9(const string &solution){
  int res=0;
  for(int i=3;i<N;i++){
    if( (solution[i]==solution[i-1]) && (solution[i-1]==solution[i-2]) && (solution[i-2]==solution[i-3]) ){
      res++;
    }
  }
  return res;
}
int F10(const string &solution){
  int res=0;
  static vector<int> a={0,0,0,0,2,2};
  for(int i=3;i<N;i++){
    vector<int> tmp(6,0);
    for(int j=i-3;j<=i;j++){
      tmp[solution[j]-'1']++;
    }
    sort(tmp.begin(),tmp.end());
    if(a==tmp){
      res++;
    }
  }
  return res;
}
int F11(const string &solution){
  int res=0;
  static vector<int> a={0,0,0,0,2,3};
  for(int i=4;i<N;i++){
    vector<int> tmp(6,0);
    for(int j=i-4;j<=i;j++){
      tmp[solution[j]-'1']++;
    }
    sort(tmp.begin(),tmp.end());
    if(a==tmp){
      res++;
    }
  }
  return res;
}
int F12(const string &solution){
  int res=0;
  for(int i=3;i<N;i++){
    if( (solution[i-3]==solution[i]) && ( (solution[i]==solution[i-2])^(solution[i]==solution[i-1]) ) ){
      res++;
    }
  }
  return res;
}
int F13(const string &solution){
  int res=0;
  for(int i=4;i<N;i++){
    if(solution[i-4]==solution[i]){
      vector<int> tmp(6,0);
      for(int j=i-3;j<i;j++){
        tmp[solution[j]-'1']++;
      }
      if(tmp[solution[i]-'1']==1){
        res++;
      }
    }
  }
  return res;
}
int F14(const string &solution){
  int res=0;
  for(int i=5;i<N;i++){
    if(solution[i-5]==solution[i]){
      vector<int> tmp(6,0);
      for(int j=i-4;j<i;j++){
        tmp[solution[j]-'1']++;
      }
      if(tmp[solution[i]-'1']==2){
        res++;
      }
    }
  }
  return res;
}
int F15(const string &solution){
  int res=0;
  for(int i=6;i<N;i++){
    if(solution[i-6]==solution[i]){
      vector<int> tmp(6,0);
      for(int j=i-5;j<i;j++){
        tmp[solution[j]-'1']++;
      }
      if(tmp[solution[i]-'1']==2){
        res++;
      }
    }
  }
  return res;
}

vector<vector<long double>> all_function(const vector<string> &solution){
  vector<vector<long double>> res(solution.size(),vector<long double>(15));
  for(int it=0;it<solution.size();it++){
    res[it][0]=F1(solution[it]);
    res[it][1]=F2(solution[it]);
    res[it][2]=F3(solution[it]);
    res[it][3]=F4(solution[it]);
    res[it][4]=F5(solution[it]);
    res[it][5]=F6(solution[it]);
    res[it][6]=F7(solution[it]);
    res[it][7]=F8(solution[it]);
    res[it][8]=F9(solution[it]);
    res[it][9]=F10(solution[it]);
    res[it][10]=F11(solution[it]);
    res[it][11]=F12(solution[it]);
    res[it][12]=F13(solution[it]);
    res[it][13]=F14(solution[it]);
    res[it][14]=F15(solution[it]);
  }

  return res;
}


pair<long double,long double> find_midPoint(const long double small_feature,const long double small_objective,const long double large_feature,const long double large_objective,const long double gamma){
    long double X=(-gamma*large_feature+large_objective-gamma*small_feature-small_objective)/(-2.0*gamma);
    long double Y=(gamma*(large_feature-small_feature)-(large_objective+small_objective))/(-2.0);

    long double x,y;

    //x=X- ( (X)-(long long )X );//特徴量は切り捨てる(f1-f6は無駄だけど)
    x=X;
    y=Y;

    return make_pair(x,y);
}



class old_data{
private:
  int data_count; 
  vector<vector<long double>> old_feature_data;
  vector<vector<long double>> old_objective_data;
public:
  old_data(){data_count=0;}

  void input_data(){
    ifstream Cin(OLD_ANSWER_FEATURE_DATA);


    Cin>>data_count;

    for(int xxx=0;xxx<data_count;xxx++){
      vector<long double> tmp_objective(M);
      vector<long double> tmp_feature(15);
      for(int i=0;i<M;i++){
        Cin>>tmp_objective[i];
      }
      for(int i=0;i<15;i++){
        Cin>>tmp_feature[i];
      }
      old_objective_data.emplace_back(tmp_objective);
      old_feature_data.emplace_back(tmp_feature);
      data_count++;
    }

    Cin.close();
  }

  void add_data(const vector<long double> &objective,const vector<long double> &feature){
    old_objective_data.emplace_back(objective);
    old_feature_data.emplace_back(feature);
    data_count++;
    cout<<"提出結果を保存します"<<endl;
    for(int i=0;i<objective.size();i++){
      if(i!=0) cout<<" "; 
      cout<<objective[i];
    }cout<<endl;
    for(int i=0;i<feature.size();i++){
      if(i!=0) cout<<" ";
      cout<<feature[i];
    }cout<<endl;
    

    ofstream Cout(OLD_ANSWER_FEATURE_DATA,std::ios::app | std::ios::ate);
    //Cout<<data_count<<endl;

      for(int j=0;j<M;j++){
        if(j!=0) Cout<<" ";
        Cout<<objective[j];
      }
      Cout<<endl;

      for(int j=0;j<15;j++){
        if(j!=0) Cout<<" ";
        Cout<<feature[j];
      }
      Cout<<endl;

    Cout.close();
  }

  void find_near_data(const vector<long double> &objective,const vector<long double> &feature){
    vector<vector<long double>> near_objective_data;
    vector<vector<long double>> near_feature_data;
    vector<pair<int,long double>> get_gamma;
    
    int near_data_count=0;
    for(int i=0;i<data_count;i++){
      bool near_flag=false;
      if(M==2){
        int another_data_count=0;

        for(int j=0;j<7;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=0;j<7;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[0]-old_objective_data[i][0])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j=7;j<15;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=7;j<15;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[1]-old_objective_data[i][1])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
      
      }
      else if(M==3){
        int another_data_count=0;

        for(int j= 0;j< 5;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=0;j<5;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[0]-old_objective_data[i][0])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 5;j<10;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=5;j<10;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[1]-old_objective_data[i][1])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j=10;j<15;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=10;j<15;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[2]-old_objective_data[i][2])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
      
      }
      else if(M==5){
        int another_data_count=0;
      
        for(int j= 0;j< 3;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=0;j<3;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[0]-old_objective_data[i][0])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 3;j< 6;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=3;j<6;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[1]-old_objective_data[i][1])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 6;j< 9;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=6;j<9;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[2]-old_objective_data[i][2])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 9;j<12;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=9;j<12;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[3]-old_objective_data[i][3])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j=12;j<15;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=12;j<15;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[4]-old_objective_data[i][4])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }

      }
      else if(M==7){
        int another_data_count=0;

        for(int j= 0;j< 2;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=0;j<2;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[0]-old_objective_data[i][0])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 2;j< 4;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=2;j<4;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[1]-old_objective_data[i][1])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 4;j< 6;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=4;j<6;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[2]-old_objective_data[i][2])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 6;j< 8;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=6;j<8;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[3]-old_objective_data[i][3])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j= 8;j<10;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=8;j<10;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[4]-old_objective_data[i][4])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j=10;j<12;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=10;j<12;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[5]-old_objective_data[i][5])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }
        another_data_count=0;
        for(int j=12;j<15;j++){
          if(old_feature_data[i][j]!=feature[j]) another_data_count++;
        }
        if(another_data_count==1){
          near_flag=true;
          for(int j=12;j<15;j++){
            if(old_feature_data[i][j]!=feature[j]){
              get_gamma.emplace_back(make_pair(j,abs(objective[6]-old_objective_data[i][6])/abs(feature[j]-old_feature_data[i][j]))); 
            } 
          }
        }

      }

      if(near_flag){
        near_data_count++;
        near_objective_data.emplace_back(old_objective_data[i]);
        near_feature_data.emplace_back(old_feature_data[i]);
      }

    }
    cout<<'\n';
    cout<<"過去の提出に似ているデータが"<<near_data_count<<"個あります。\n\n";
    for(int i=0;i<near_data_count;i++){
      show_vector(near_objective_data[i]);
      show_vector(near_feature_data[i]);

      cout<<endl;
    }
    for(int i=0;i<get_gamma.size();i++){
      cout<<"F"<<get_gamma[i].first+1<<"の推定ガンマ値は"<<get_gamma[i].second<<"です。"<<endl;
    }
  }

};

int main() {
  //data input start
  cout<<"プログラムを開始します"<<endl;
  load();

  while(true){
    auto solution=make_find_gamma_answer();
    if(is_answer(solution)) send_answer(solution);
  }

  return 0;
}

string make_find_gamma_answer(){
  string ans(N,'1');
  for(int i=0;i<N;i++){
    ans[i]=(char)('0'+random_1to6(mt));
  }

  return ans;
}


long double scoring_known(const long double &f){
  double res=0.0;

  const int now=11-1;//既知番号

  if(f<ALPHA[now]){
    res=GAMMA[now]*(ALPHA[now]-f);
  }
  else if(f>BETA[now]){
    res=GAMMA[now]*(f-BETA[now]);
  }
  else{
    res=0.0;
  }


  return res;
}

vector<string> make_find_alpha_beta_answer(const long double gamma,const pair<long double,long double> &mid){
  long double d,estimation_objective;
  d=mid.first;
  estimation_objective=mid.second;

  cout<<d<<" "<<estimation_objective<<endl;

  vector<string> ans;
  string tmp(N,'1');
  //F15変更 F13,14固定(0,0)

  //mid=f 1122211 1122211...
  int D=d;
  tmp="";
  while(tmp.size()<N){
    tmp+='1';if(tmp.size()==N) break;
    tmp+='1';if(tmp.size()==N) break;
    tmp+='2';if(tmp.size()==N) break;
    tmp+='2';if(tmp.size()==N) break;
    tmp+='2';if(tmp.size()==N) break;
    tmp+='1';if(tmp.size()==N) break;
    tmp+='1';if(tmp.size()==N) break;
  }

  if((D==0)||(D==1)){
    for(int i=D+6;i<N;i++){
      tmp[i]=(char)('3'+(i%4));
    }
  }
  else{
    for(int i=D+10+((D-2)/3)*4;i<N;i++){
      tmp[i]=(char)('3'+(i%4));
    }
  }

  ans.emplace_back(tmp);

  return ans;
}