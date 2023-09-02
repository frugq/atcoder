template<class Dist>
class BFS{
public:
    int n, zero, inf;
    vector<int> start;
    vector<vector<int>> road;
    vector<Dist> dist;

    BFS(){}
    BFS(int N, const vector<int>& Start, Dist Zero, Dist Inf);
    void resize(int N, const vector<int>& Start, Dist Zero, Dist Inf);
    void makeRoad(int u, int v);
    void clear();
    void solve();
    vector<int> getPath(int end);
};

template<class Dist>
ostream& operator <<(ostream& os, const BFS<Dist>& bfs);

template<class Dist>
BFS<Dist>::BFS(int N, const vector<int>& Start, Dist Zero, Dist Inf){
    resize(N, Start, Zero, Inf);
}

template<class Dist>
void BFS<Dist>::resize(int N, const vector<int>& Start, Dist Zero, Dist Inf){
    n = N;
    start = Start;
    zero = Zero;
    inf = Inf;
    road.resize(n);
    dist.resize(n, inf);
}

template<class Dist>
void BFS<Dist>::makeRoad(int u, int v){
    road.at(u).push_back(v);
}

template<class Dist>
void BFS<Dist>::solve(){
    queue<int> que;
    for(const auto& e : start){
        que.emplace(e);
        dist.at(e) = zero;
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto& nxt : road.at(now)){
            if(chmin(dist.at(nxt), dist.at(now) + 1)){
                que.emplace(nxt);
            }
        }
    }
}

template<class Dist>
void BFS<Dist>::clear(){
    for(auto&& e : dist) e - inf;
}

template<class Dist>
vector<int> BFS<Dist>::getPath(int end){
    assert(dist.at(end) < inf);
    int now = end;
    vector<int> result = {end};
    for(int i = dist.at(end); i > 0; --i){
        int pre = -1;
        for(const auto& e : road.at(now)){
            if(dist.at(e) == i - 1){
                pre = e;
                break;
            }
        }
        assert(pre != -1);
        now = pre;
        result.push_back(now);
    }
    reverse(result.begin(), result.end());
    return result;
}

template<class Dist>
ostream& operator <<(ostream& os, const BFS<Dist>& bfs){
    os << endl;
    for(int i = 0; i < SIZE(bfs.road); ++i){
        os << left << setw(2) << i << " -> ";
        for(const auto& e : bfs.road.at(i)){
            os << e << " ";
        }
        os << endl;
    }
    return os;
}
