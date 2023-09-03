#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#ifdef __LOCAL
#include "debug.h"
#endif
#define SIZE(x) (int)(x.size())
using ll = long long;
template<class T>bool chmin(T& x,T y){if(x>y){x=y;return true;}return false;}
template<class T>bool chmax(T& x,T y){if(x<y){x=y;return true;}return false;}
random_device rnd;

class State{
public:
    ll score = 0;
    bool operator <(State y){
        return score < y.score;
    }
};

void input(int testCase = -1);
void output(const State& state);

int main(){
    input();
    State bestState;

    output(bestState);
    return 0;
}


void input(int testCase = -1){
    if(testCase == -1){

    }else{
        stringstream fileName;
        fileName << "in/" << setw(4) << setfill('0') << testCase << ".txt";
        ifstream ifs;
        ifs.open(fileName.str());
        assert(ifs);

    }
}

void output(const State& state){
    
    fprintf(stderr, "score = %f\n", state.score * 1e-6);
}
