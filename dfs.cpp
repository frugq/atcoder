class DFS{
public:
    int n;
    vector<vector<int>> road;
    void sub_solve(int now, int back);
    DFS(int N);
    int cnt_seen;
    vector<int> color;
    vector<bool> seen;
    vector<int> pos2ord, ord2pos, rpos2ord, rord2pos, euler;
    void makeRoad(int u, int v);
    void solve(int start);
};
ostream& operator<<(ostream& os, const DFS& dfs);

DFS::DFS(int n_) : n(n_){
    cnt_seen = 0;
    road.resize(n);
    seen.resize(n, false);
    pos2ord.resize(n);
    rpos2ord.resize(n);
    color.resize(n);
}

void DFS::makeRoad(int u, int v){
    road.at(u).push_back(v);
}

void DFS::solve(int start){
    seen.at(start) = true;
    cnt_seen++;
    pos2ord.at(start) = size(pos2ord);
    ord2pos.push_back(start);
    sub_solve(start, -1);
    color.at(start) = false;
}

void DFS::sub_solve(int now, int back){
    euler.push_back(now);
    for(const auto& next : road.at(now)){
        if(next == back) continue;
        if(seen.at(next)) continue;
        color.at(next) = !color.at(now);
        pos2ord.at(next) = size(ord2pos);
        ord2pos.push_back(next);
        seen.at(next) = true;
        cnt_seen++;
        sub_solve(next, now);
        euler.push_back(now);
    }
    rpos2ord.at(now) = size(rord2pos);
    rord2pos.push_back(now);
}

ostream& operator<<(ostream& os, const DFS& dfs){
    os << endl;
    for(int i = 0; i < SIZE(dfs.road); ++i){
        os << left << setw(2) << i << " -> ";
        for(const auto& e : dfs.road.at(i)){
            os << e << " ";
        }
        os << endl;
    }
    return os;
}
