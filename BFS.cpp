class BFS{
public:
    int n, zero = 0, inf = 1 << 30;
    vector<int> start;
    vector<vector<int>> road;
    vector<int> dist;

    BFS(){}
    BFS(int N, const vector<int>& Start);
    void resize(int N, const vector<int>& Start);
    void makeRoad(int u, int v);
    void clear();
    void solve();
    vector<int> getPath(int end);
};

ostream& operator <<(ostream& os, const BFS& bfs);

BFS::BFS(int N, const vector<int>& Start){
    resize(N, Start);
}

void BFS::resize(int N, const vector<int>& Start){
    n = N;
    start = Start;
    road.resize(n);
    dist.resize(n, inf);
}

void BFS::makeRoad(int u, int v){
    road.at(u).push_back(v);
}

void BFS::solve(){
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

void BFS::clear(){
    for(auto&& e : dist) e = inf;
}

vector<int> BFS::getPath(int end){
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

ostream& operator <<(ostream& os, const BFS& bfs){
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
