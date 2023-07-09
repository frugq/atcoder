template<class Dist>
class Dijkstra{
public:
    using Troad = tuple<Dist, int>;
    using Tque = tuple<Dist, int>;
    int n;
    Dist zero, inf;
    vector<vector<Troad>> road;      //u -> (v, cost)
    vector<Dist> dist;
    vector<bool> seen;

    Dijkstra(int N, Dist Zero, Dist Inf);
    void makeRoad(int u, int v, Dist cost);
    void solve(int start);
    void printroad();
    void clear();
};

template<class Dist>
Dijkstra<Dist>::Dijkstra(int N, Dist Zero, Dist Inf){
    n = N;
    inf = Inf;
    zero = Zero;
    road.resize(N);
    dist.resize(N, inf);
    seen.resize(N, false);
}

template<class Dist>
void Dijkstra<Dist>::makeRoad(int u, int v, Dist cost){
    road.at(u).push_back(make_pair(v, cost));
}

template<class Dist>
void Dijkstra<Dist>::solve(int start){
    priority_queue<Tque, vector<Tque>, greater<Tque>> que;
    que.emplace(make_tuple(zero, start));
    dist.at(start) = zero;
    while(!que.empty()){
        auto [nowDist, nowPos] = que.top();
        que.pop();
        if(seen.at(nowPos)) continue;
        seen.at(nowPos) = true;
        for(const auto& [nxtPos, addDist] : road.at(nowPos)){
            Dist nxtDist = dist.at(nowPos) + addDist;
            if(chmin(dist.at(nxtPos), dist.at(nowPos) + addDist)){
                que.emplace(make_tuple(nxtDist, nxtPos));
            }
        }
    }
}

template<class Dist>
void Dijkstra<Dist>::printroad(){
    for(int i = 0; i < size(road); ++i){
        for(const auto& e : road.at(i)){
            cout << right << " " << setw(2) << i ;
            cout << " -> " << setw(2) << get<0>(e);
            cout << "  [" << setw(2) << get<1>(e) << "]" << endl;
        }
    }
}

template<class Dist>
void Dijkstra<Dist>::clear(){
    for(int i = 0; i < n; ++i){
        seen.at(i) = false;
        dist.at(i) = inf;
    }
}
