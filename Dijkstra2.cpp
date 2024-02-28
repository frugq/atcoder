#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#ifdef __LOCAL
#include "debug2.h"
#endif
#ifndef __LOCAL
#define show(...) 
#define SET_GROUP(x)
#define SET_MAXCNT(x)
#endif
#define SIZE(x) (int)(x.size())
#define ALL(x) x.begin(),x.end()
using ll = long long;
template<class T>bool chmin(T& x,T y){if(x>y){x=y;return true;}return false;}
template<class T>bool chmax(T& x,T y){if(x<y){x=y;return true;}return false;}
template<class T>vector<T>matrix(int n1,T val){return vector<T>(n1,val);}
template<class T>vector<vector<T>>matrix(int n1,int n2,T val){return vector<vector<T>>(n1,matrix<T>(n2,val));}
template<class T>vector<vector<vector<T>>>matrix(int n1,int n2,int n3,T val){return vector<vector<vector<T>>>(n1,matrix<T>(n2,n3,val));}
template<class T>vector<vector<vector<vector<T>>>>matrix(int n1,int n2,int n3,int n4,T val){return vector<vector<vector<vector<T>>>>(n1,matrix<T>(n2,n3,n4,val));}

template<class Dist>
class Dijkstra{
public:
    struct Road{
        Dist dist;
    };
    using Tque = tuple<Dist, int>;  //(dist, to)
    using Troad = tuple<int, Road>;

    int n;
    Dist zero, inf;
    vector<vector<Troad>> road;      //from -> (to, cost)
    vector<Dist> dist;
    vector<bool> seen;
    vector<int> start;
    priority_queue<Tque, vector<Tque>, greater<Tque>> que;

    Dijkstra(){}

    Dijkstra(int N, Dist Zero, Dist Inf, const vector<int>& Start){
        resize(N, Zero, Inf, Start);
    }

    void resize(int N, Dist Zero, Dist Inf, const vector<int>& Start){
        road.clear();
        dist.clear();
        seen.clear();
        while(!que.empty()) que.pop();

        n = N;
        inf = Inf;
        zero = Zero;
        road.resize(N);
        dist.resize(N, inf);
        seen.resize(N, false);
        start = Start;
        for(const auto& e : start){
            dist.at(e) = zero;
            que.emplace(Tque(zero, e));
        }
    }

    void makeRoad(int u, int v, Road r){
        road.at(u).push_back(make_pair(v, r));
    }

    void solve(){
        while(!que.empty()){
            int nowPos = get<1>(que.top());
            que.pop();
            if(seen.at(nowPos)) continue;
            seen.at(nowPos) = true;
            for(const auto& e : road.at(nowPos)){
                int nxtPos = get<0>(e);
                Dist nxtDist = dist.at(nowPos) + get<1>(e).dist;
                if(nxtDist < zero) continue;//オーバーフロー対策
                if(chmin(dist.at(nxtPos), nxtDist)){
                    que.emplace(make_tuple(nxtDist, nxtPos));
                }
            }
        }
    }

    void printroad(){
        for(int i = 0; i < SIZE(road); ++i){
            for(const auto& e : road.at(i)){
                cout << right << " " << setw(2) << i ;
                cout << " -> " << setw(2) << get<0>(e);
                cout << "  [" << setw(2) << get<1>(e).dist << "]" << endl;
            }
        }
    }

    void clear(){
        for(int i = 0; i < n; ++i){
            seen.at(i) = false;
            dist.at(i) = inf;
        }
    }
};

int main(){
    ll n, a, b, c, inf = 1LL << 60;
    cin >> n >> a >> b >> c;
    Dijkstra<ll> dij1(n, 0, inf, {0});
    Dijkstra<ll> dijN(n, 0, inf, {(int)n - 1});

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){
        ll d;
        cin >> d;
        dij1.makeRoad(i, j, Dijkstra<ll>::Road(d * a));
        dijN.makeRoad(i, j, Dijkstra<ll>::Road(d * b + c));
    }

    dij1.solve();
    dijN.solve();
    ll ans = inf;
    for(int i = 0; i < n; ++i){
        chmin(ans, dij1.dist.at(i) + dijN.dist.at(i));
    }
    dij1.printroad();
    //show(dij1.dist);
    //show(dijN.dist);
    cout << ans << endl;
    return 0;
}
