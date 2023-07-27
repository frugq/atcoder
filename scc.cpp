
typedef struct{
    vector<vector<int>> graph;
    vector<int> idx;
    vector<pair<int, int>> road;
} SCC_graph;

SCC_graph scc(int n, const vector<pair<int, int>>& road);

SCC_graph scc(int n, const vector<pair<int, int>>& road){
    DFS dfs(n), rdfs(n);
    SCC_graph result;
    set<pair<int, int>> st_new_road;

    //道でつなぐ
    for(const auto& [u, v] : road){
        dfs.makeRoad(u, v);
        rdfs.makeRoad(v, u);
    }
    //dfs帰りがけの順番を記録
    for(int i = 0; i < n; ++i){
    if(dfs.seen.at(i)) continue;
        dfs.solve(i);
    }
    //順番が大きいものからdfs、通ったものを1つのグループへ
    reverse(dfs.rord2pos.begin(), dfs.rord2pos.end());
    for(const auto& e : dfs.rord2pos){
        if(rdfs.seen.at(e)) continue;
        rdfs.solve(e);
        result.graph.push_back(rdfs.ord2pos);
        rdfs.ord2pos.clear();
    }
    //強連結成分分解後の番号をつける
    result.idx.resize(n);
    for(int i = 0; i < SIZE(result.graph); ++i){
        for(const auto& e : result.graph.at(i)){
            result.idx.at(e) = i;
        }
    }
    //強連結成分分解後の道を作る
    for(const auto& [u, v] : road){
        int new_u = result.idx.at(u);
        int new_v = result.idx.at(v);
        if(new_u != new_v){
            st_new_road.emplace(make_pair(new_u, new_v));
        }
    }
    for(const auto& [u, v] : st_new_road){
        result.road.push_back(make_pair(u, v));
    }
    return result;
}
