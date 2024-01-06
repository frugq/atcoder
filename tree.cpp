template<class Dist>
class Tree{
public:
    int n, root, idxRoad = 0, log2N = 0;
    const int int_inf = 1 << 30;
    Dist zero, inf;

    struct Road{
        int from, to;
        Dist dist;
        int id;
        int upper, lower;
    };

    vector<Road> listRoad;
    vector<vector<Road>> road;
    vector<Dist> initDist;
    vector<bool> seen;
    vector<int> simpleDist, eularPath, leftIdx, rightIdx;
    vector<vector<int>> preTown;
    fenwick_tree<Dist> bit;

    void dfs(int now){
        seen.at(now) = true;
        for(const auto& nxt : road.at(now)){
            if(seen.at(nxt.to)) continue;
            listRoad.at(nxt.id).upper = now;
            listRoad.at(nxt.id).lower = nxt.to;
            initDist.at(nxt.to) = initDist.at(now) + nxt.dist;
            simpleDist.at(nxt.to) = simpleDist.at(now) + 1;
            preTown.at(nxt.to).at(0) = now;
            eularPath.push_back(now);
            dfs(nxt.to);
        }
        eularPath.push_back(now);
    }
   
    int lca(int u, int v){
        int d1 = simpleDist.at(u);
        int d2 = simpleDist.at(v);
        u = preKthTown(u, d1 - min(d1, d2));
        v = preKthTown(v, d2 - min(d1, d2));
        int l = -1, r = n;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(preKthTown(u, mid) == preKthTown(v, mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        return preKthTown(u, r);
    }

public:
    Tree(int N, Dist Zero, Dist Inf, int Root = 0): bit(2 * N){
        n = N;
        zero = Zero;
        inf = Inf;
        root = Root;
        int copyN = n;
        while(copyN > 0) copyN >>= 1, log2N++;
        road.resize(n);
        seen.resize(n, false);
        simpleDist.resize(n, int_inf);
        simpleDist.at(root) = 0;
        initDist.resize(n, inf);
        initDist.at(root) = zero;
        leftIdx.resize(n, int_inf);
        rightIdx.resize(n, -1);
        preTown.resize(n, vector<int>(log2N, root));
    }
    
    void makeRoad(int u, int v, Dist d){
        listRoad.push_back(Road(u, v, d, idxRoad, -1, -1));
        road.at(u).push_back(Road(u, v, d, idxRoad, -1, -1));
        road.at(v).push_back(Road(v, u, d, idxRoad, -1, -1));
        idxRoad++;
    }

    void update(){
        dfs(root);
        //for(int i = 0; i < n; ++i) assert(seen.at(i));
        //for(const auto& e : listRoad) assert(simpleDist.at(e.upper) < simpleDist.at(e.lower));

        for(int i = 0; i < SIZE(eularPath); ++i){
            chmin(leftIdx.at(eularPath.at(i)), i);
            chmax(rightIdx.at(eularPath.at(i)), i);
            if(i > 0) bit.add(i, initDist.at(eularPath.at(i)) - initDist.at(eularPath.at(i - 1)));
        }

        for(int j = 1; j < log2N; ++j){
            for(int i = 0; i < n; ++i){
                preTown.at(i).at(j) = preTown.at(preTown.at(i).at(j - 1)).at(j - 1);
            }
        }
    }

    int preKthTown(int x, int k){
        for(int i = 0; i < log2N && k > 0; ++i){
            if(k & 1) x = preTown.at(x).at(i);
            k >>= 1;
        }
        return x;
    }

    void changeRoadDist(int i, Dist dist){
        int lowerTown = listRoad.at(i).lower;
        bit.add(leftIdx.at(lowerTown), dist - listRoad.at(i).dist);
        bit.add(rightIdx.at(lowerTown) + 1, -(dist - listRoad.at(i).dist));
        listRoad.at(i).dist = dist;
    }

    Dist calcDist(int u, int v){
        return bit.sum(0, leftIdx.at(u) + 1) + bit.sum(0, leftIdx.at(v) + 1) - 2 * bit.sum(0, leftIdx.at(lca(u, v)) + 1);
    }

    #ifdef __LOCAL
    friend int push(Tree tree){
        debug::output.str("");
        for(int i = 0; i < min<int>(debug::maxDispCnt, SIZE(tree.listRoad)); ++i){
            const auto& e = tree.listRoad.at(i);
            debug::push("[");
            debug::push(e.id);
            debug::push("]");
            debug::push(e.from);
            debug::push("->");
            debug::push(e.to);
            debug::push("(");
            debug::push(e.from);
            debug::push("->");
            debug::push(e.to);
            debug::push(")");
            debug::push(e.dist);
            debug::push("\n");
        }
        debug::push("\n");

        for(int i = 0; i < min<int>(debug::maxDispCnt, tree.n); ++i){
            debug::push(tree.bit.sum(0, tree.leftIdx.at(i) + 1));
        }
        return 2;
    }
    #endif
};
