//  C
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <random>

#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#include "debug2.h"
#endif
#ifndef __LOCAL
#define show(...) 
#define SET_GROUP(x)
#define SET_MAXCNT(x)
#endif

using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//using bigint = cpp_int;

#define SIZE(x) (ll)(x.size())
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);++i)
#define repp(i,l,r) for(ll i=(ll)(l);i<(ll)(r);++i)
#define print(x) cout<<(x)<<endl;
#define printyn(x) print(x?"Yes":"No");
#define at2d(i, j) at(i).at(j)
#define at3d(i, j, k) at(i).at(j).at(k)
#define at4d(i, j, k, l) at(i).at(j).at(k).at(l)
using ll = long long;
//int di[] = {1, 0, -1, 0, 1, -1, -1, 1};
//int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};
//string dc = "DULR";
//map<char, int> c2dir = {{'D', 0}, {'R', 1}, {'U', 2}, {'L', 3}};
//bool inside(int i, int j) {return 0 <= i && i < h && 0 <= j && j < w;}
template<class T>bool chmin(T& x, T y) { if (x > y) { x = y; return true; }return false; }
template<class T>bool chmax(T& x, T y) { if (x < y) { x = y; return true; }return false; }
template<class T>vector<T>matrix(int n1, T val) { return vector<T>(n1, val); }
template<class T>vector<vector<T>>matrix(int n1, int n2, T val) { return vector<vector<T>>(n1, matrix<T>(n2, val)); }
template<class T>vector<vector<vector<T>>>matrix(int n1, int n2, int n3, T val) { return vector<vector<vector<T>>>(n1, matrix<T>(n2, n3, val)); }
template<class T>vector<vector<vector<vector<T>>>>matrix(int n1, int n2, int n3, int n4, T val) { return vector<vector<vector<vector<T>>>>(n1, matrix<T>(n2, n3, n4, val)); }
template<class T>T sum(vector<T>x) { T r = 0; for (auto e : x)r += e; return r; }
template<class T>T max(vector<T>x) { T r = x[0]; for (auto e : x)chmax(r, e); return r; }
template<class T>T min(vector<T>x) { T r = x[0]; for (auto e : x)chmin(r, e); return r; }
template<class T>set<T>toSet(vector<T>x) { set<T> r; for (auto e : x)r.emplace(e); return r; }
template<class T>map<T, ll>toMap(vector<T>x) { map<T, ll>mp; for (auto e : x)mp[e]++; return mp; }
template<class T>vector<T>toVector(set<T>x) { vector<T> r; for (auto e : x)r.push_back(e); return r; }
template<class T1, class T2>pair<T1, T2> operator+(pair<T1, T2>x, pair<T1, T2>y) { return make_pair(x.first + y.first, x.second + y.second); }
template<class T1, class T2>pair<T1, T2> operator-(pair<T1, T2>x, pair<T1, T2>y) { return make_pair(x.first - y.first, x.second - y.second); }
template<class T1, class T2>istream& operator>>(istream& is, tuple<T1, T2>& x) { cin >> get<0>(x) >> get<1>(x); return is; }
template<class T1, class T2, class T3>istream& operator>>(istream& is, tuple<T1, T2, T3>& x) { cin >> get<0>(x) >> get<1>(x) >> get<2>(x); return is; }
template<class T1, class T2>istream& operator>>(istream& is, pair<T1, T2>& x) { cin >> x.first >> x.second; return is; }
template<class T>istream& operator>>(istream& is, vector<T>& x) { for (auto&& e : x)is >> e; return is; }
template<class T>istream& operator>>(istream& is, vector<vector<T>>& x) { for (auto&& e : x)for (auto&& f : e)is >> f; return is; }
template<class T>ostream& operator<<(ostream& os, const vector<T>& x) { for (auto e : x)os << e << " "; return os; }
template<class T>ostream& operator<<(ostream& os, const vector<vector<T>>& x) { for (auto e : x) { for (auto f : e)os << f << " "; os << "\n"; }return os; }
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
