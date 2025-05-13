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
