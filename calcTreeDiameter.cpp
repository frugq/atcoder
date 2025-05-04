template<class Dist>
tuple<ll, int, int> calcTreeDiameter(Dijkstra<Dist>& dij){//dist, i, j
    dij.clear();
    dij.solve(0);
    int pos = -1;
    ll val = 0;
    rep(i, dij.n){
        if(val < dij.dist[i]){
            pos = i;
            val = dij.dist[i];
        }
    }
    dij.clear();
    dij.solve(pos);
    int pos2 = -1;
    ll val2 = 0;
    rep(i, dij.n){
        if(val2 < dij.dist[i]){
            pos2 = i;
            val2 = dij.dist[i];
        }
    }
    return make_tuple(val2, pos, pos2);
}
