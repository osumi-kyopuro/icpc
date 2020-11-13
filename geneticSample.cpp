#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

void scoring();
void sortPopulation();
void selectPopulation();
void crossoverPopulation();
void mutatePopulation();
void showBestGenome(const int generation);

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> rand0to9(0,9);//0~10の整数をランダムで生成
uniform_int_distribution<> randChar(0,255);//0~255の整数をランダムで生成

//遺伝子情報
struct genome{
    string s;
    int score;

    genome(){s="";score=1000000000;}
    genome(const string &t):s(t),score(1000000000){}

    bool operator<(const genome &another){
        return score<another.score;
    }
    bool operator>(const genome &another){
        return score>another.score;
    }
    //この遺伝子の突然変異
    void mutation(){
        uniform_int_distribution<> randIndex(0,max((int)s.size()-1,0));
        int k=rand0to9(mt);
        if((k==0)||(k==1)){
            //どこか1箇所の文字を変更する
            if(s.size()==0) return;
            s[randIndex(mt)]=(char)randChar(mt);
        }
        else if((k==2)||(k==3)){
            //末尾に文字を追加
            char c=randChar(mt);
            s+=c;
        }
        else if(k==4){
            //どこかの文字を削除
            if(s.size()==0) return;
            s.erase(randIndex(mt),1);
        }
        else{
            //何もしない
        }
    }
    //この遺伝子と別の遺伝子との交叉(交配)
    void crossover(genome &another){
        int loop=min(s.size(),another.s.size());
        for(int i=0;i<loop;++i){
            if(rand0to9(mt)<4){
                swap(s[i],another.s[i]);
            }
        }
    }
};



constexpr int POPULATION_SIZE=500;//個体の数
vector<genome> population(POPULATION_SIZE);
string target="Hello, World";//目指したい文字列
genome bestGenome;//これまでの世代で最も良い遺伝子




int main(){
    cin.tie();
    int generation=0;//個体の世代

    while(++generation<500){
        sortPopulation();//ソート
        this_thread::sleep_for(chrono::milliseconds(50));
        showBestGenome(generation);
        if(bestGenome>population[0]){
            bestGenome=population[0];
        }
        selectPopulation();//淘汰
        crossoverPopulation();//交叉(交配)
        mutatePopulation();//突然変異
        scoring();
    }

}


//各々の個体でスコアを測定する(少ない方が良い遺伝子)
void scoring(){
    static const int targetLength=target.size();
    for(int i=0;i<POPULATION_SIZE;++i){
        string t=population[i].s;
        int score=0;
        const int length=t.size();
        const int loop=min(length,targetLength);
        //長さが異なるほど最適解から遠い
        score+=abs(targetLength-length)*1000;
        for(int j=0;j<loop;++j){
            //文字が異なるほど最適解から遠い
            score+=abs(t[j]-target[j])*1;
        }

        population[i].score=score;
    }
}

//個体を良い順にソート
void sortPopulation(){
    sort(population.begin(),population.end());
}

//適用度の低いゲノムを淘汰する関数
void selectPopulation(){
    for(int i=0;i<POPULATION_SIZE/2;++i){
        population[i+(POPULATION_SIZE/2)]=population[i];
    }
}
//遺伝子交配(交叉)をする関数
void crossoverPopulation(){
    for(int i=POPULATION_SIZE/2+1;i<POPULATION_SIZE;++i){
        population[i].crossover(population[i-1]);
    }
}

//突然変異をする関数
void mutatePopulation(){
    for(int i=POPULATION_SIZE/2;i<POPULATION_SIZE;++i){
        population[i].mutation();
    }
}

//現状最も良い遺伝子情報を持つものを表示する関数
void showBestGenome(const int generation){
    cout<<right<<setw(3)<<generation<<"世代目の最も良い解:"<<bestGenome.s<<endl;
}