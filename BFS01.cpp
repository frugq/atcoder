class BFS01{
public:
	using T_road = tuple<int, int>;
	int n, zero = 0, inf = 1 << 30;
	vector<int> start;
	vector<vector<T_road>> road;
	vector<int> dist, pre;

	BFS01(){}
	BFS01(int N, const vector<int>& Start);
	void resize(int N, const vector<int>& Start);
	void makeRoad(int u, int v, int w);
	void clear();
	void solve();
	vector<int> getPath(int end);
};
ostream& operator <<(ostream& os, const BFS01& bfs);

BFS01::BFS01(int N, const vector<int>& Start){
    resize(N, Start);
}

void BFS01::resize(int N, const vector<int>& Start){
	n = N;
	start = Start;
	road.resize(n);
	dist.resize(n, inf);
	pre.resize(n, -1);
}

void BFS01::makeRoad(int u, int v, int w){
    road.at(u).push_back({v, w});
}

void BFS01::solve(){
	deque<int> que;
	for(const auto& e : start){
		que.emplace_back(e);
		dist.at(e) = zero;
	}
	while(!que.empty()){
		int now = que.front();
		que.pop_front();
		for(const auto& [nxt, w] : road.at(now)){
			if(w == 1){
				if(chmin(dist.at(nxt), dist.at(now) + 1)){
					que.emplace_back(nxt);
					pre.at(nxt) = now;
				}
			}else{
				if(chmin(dist.at(nxt), dist.at(now))){
					que.emplace_front(nxt);
					pre.at(nxt) = now;
				}
			}
		}
	}
}

void BFS01::clear(){
    for(auto&& e : dist) e = inf;
}

vector<int> BFS01::getPath(int end){
    assert(dist.at(end) < inf);
	vector<int> result;
	int now = end;
	while(true){
		result.push_back(now);
		now = pre.at(now);
	}
    return result;
}

ostream& operator <<(ostream& os, const BFS01& bfs){
	os << endl;
    for(int i = 0; i < SIZE(bfs.road); ++i){
        for(const auto& [v, w] : bfs.road.at(i)){
			os << left << setw(3) << i << " -> " << setw(3) << v << " [" << w << "]" << endl;
        }
    }
    return os;
}
