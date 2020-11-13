#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;
constexpr double mathPI=3.1415926535897932384626;
constexpr int POPULATION_SIZE=1000;//�̂̐�
constexpr int MAX_FUNCTION_SIZE=10;
const double W=0.78;//����W
const double Cp=0.69;//�n�C�p�[�p�����[�^Cp
const double Cg=0.66;//�n�C�p�[�p�����[�^Cg
const vector<double> target(MAX_FUNCTION_SIZE);

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> randomInteger(0,1e9);//0~255�̐����������_���Ő���
double randomDouble();
double randomDouble0to1();

//�eparticle�̏��
struct particle{
private:
    void init(){
        now.resize(target.size());
        personalBest.resize(target.size());
        globalBest.resize(target.size());
        v.resize(target.size());
        personalBestScore=1e18;

        for(int i=0;i<target.size();++i){
            now[i]=randomDouble();
            personalBest[i]=randomDouble();
            globalBest[i]=randomDouble();
            v[i]=randomDouble();
        }
    }
public:
    vector<double> now;//���ݒn�_
    vector<double> personalBest;//����particle�̉ߋ��̒T���n�_�̂��������Ƃ��悢�_�B
    vector<double> globalBest;//�S�Ă�particle�̉ߋ��̒T���n�_�̂��������Ƃ��悢�_�B
    double personalBestScore;//����particle�̉ߋ��̒T���n�_�̂����ł��ǂ��X�R�A
    vector<double> v;//����particle�̑��x�x�N�g��

    particle(){
        init();
    }

    //���̈�`�q�̃X�R�A�Ɣ�r����
    bool operator<(const particle &another){
        return personalBestScore<another.personalBestScore;
    }
    bool operator>(const particle &another){
        return personalBestScore>another.personalBestScore;
    }

    void next(){
        for(int i=0;i<target.size();++i){
            now[i]+=v[i];
        }
        const double r1=randomDouble0to1();
        const double r2=randomDouble0to1();
        for(int i=0;i<target.size();++i){
            v[i]=W*v[i]+Cp*r1*(personalBest[i]-now[i])+Cg*r2*(globalBest[i]-now[i]);
        }
    }

    void reborn(){
        for(int i=0;i<target.size();++i){
            v[i]=randomDouble();
        }
    }
};


vector<particle> population(POPULATION_SIZE);
vector<double> bestAnswer;//����܂ł̐���ōł��ǂ���`�q
double bestScore=1e18;
bool isBest();
void scoring();
void sortPopulation();
void showBestParticle(const int generation);
//void globalBestUpdate();
void particleMove();
void updateBestParticle();
void reject();

template <class T>
bool chmin(T& a, const T& b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int generation=0;//�̂̐���
    scoring();
    bool flag=true;
    while(flag){
        //sortPopulation();//�\�[�g
        updateBestParticle();
        showBestParticle(++generation);//������ł����Ƃ��ǂ�����\��
        flag=isBest();
        particleMove();//�eparticle�𓮂���
        scoring();//�e�̂̈�`�q�̃X�R�A��]������
        //globalBestUpdate();//�S�Ă�particle�ɂ��āAglobalBest�̍X�V���s���B
        //this_thread::sleep_for(chrono::milliseconds(50));
        if(generation%200==0){
            reject();
        }
    }

}


void reject(){
    for(int i=0;i<POPULATION_SIZE;++i){
        population[i].reborn();
    }
}

double randomDouble(){
    double res=randomInteger(mt);
    res/=1e8;
    if(randomInteger(mt)&1){
        res*=-1;
    }
    return res;
}
double randomDouble0to1(){
    double res=randomInteger(mt);
    res/=1e9;
    return res;
}
bool isBest(){
    double miss=20+exp(1.0);
    double powSum=0.0;
    double cosSum=0.0;
    for(int i=0;i<target.size();++i){
        powSum+=pow(bestAnswer[i],2);
        cosSum+=cos(2*mathPI*bestAnswer[i]);
    }
    miss-=20*exp(-0.2*sqrt(powSum/target.size()));
    miss-=exp(cosSum/target.size());
    return (miss>1e-7);
}

//�e�X�̌̂ŃX�R�A�𑪒肷��(���Ȃ������ǂ���`�q)
void scoring(){
    static const int targetLength=target.size();
    for(int i=0;i<POPULATION_SIZE;++i){
        vector<double> t=population[i].now;
        double score=20+exp(1.0);
        double powSum=0.0;
        double cosSum=0.0;
        for(int j=0;j<targetLength;++j){
            powSum+=pow(t[j],2);
            cosSum+=cos(2*mathPI*t[j]);
        }
        score-=20*exp(-0.2*sqrt(powSum/target.size()));
        score-=exp(cosSum/target.size());
        if(chmin(population[i].personalBestScore,score)){
            population[i].personalBest=t;
        }
    }
}

//�̂�ǂ����Ƀ\�[�g
void sortPopulation(){
    sort(population.begin(),population.end());
}

//����ł��ǂ�����\������֐�
void showBestParticle(const int generation){
    cout<<bestScore<<endl;
    cout<<right<<setw(3)<<generation<<"����ڂ̍ł��ǂ���`�q: {";
    for(int i=0;i<target.size();i++){
        if(i!=0) cout<<" ";
        cout<<bestAnswer[i];
    }
    cout<<"}"<<endl;
}
/*
void globalBestUpdate(){
    double score=1e18;
    vector<double> tmp(target.size());
    for(int i=0;i<POPULATION_SIZE;++i){
        if(score<population[i].personalBestScore){
            tmp=population[i].globalBest;
            score=population[i].personalBestScore;
        }
    }
    for(int i=0;i<POPULATION_SIZE;++i){
        population[i].globalBest=tmp;
    }
}
*/

void particleMove(){
    for(int i=0;i<POPULATION_SIZE;++i){
        population[i].next();
    }
}

void updateBestParticle(){
    double score=1e18;
    vector<double> best(target.size());
    for(int i=0;i<POPULATION_SIZE;++i){
        if(score>population[i].personalBestScore){
            score=population[i].personalBestScore;
            best=population[i].personalBest;
        }
    }

    for(int i=0;i<POPULATION_SIZE;++i){
        population[i].globalBest=best;
    }

    bestScore=score;
    bestAnswer=best;
}