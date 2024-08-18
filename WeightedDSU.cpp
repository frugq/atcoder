class WeightedDSU {
  public:
    WeightedDSU() : _n(0) {}
    WeightedDSU(int n) : _n(n), parent_or_size(n, -1), weight(n, 0) {}

    int merge(int a, int b, ll w) {	//w[a] - w[b] = wとなるようにつなぐ,xがrootになるようにつなぐ
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
		w -= weight.at(a) - weight.at(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w = -w;
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
		weight.at(y) = -w;
        return x;
    }

    int same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {//leaderを呼び出すと自動でaのparがrootになる。同時にweightを更新する
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
		int par = parent_or_size.at(a);
        parent_or_size[a] = leader(parent_or_size[a]);
		weight.at(a) += weight.at(par);
		return parent_or_size.at(a);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

	ll calcWeight(int x){//rootから見た重み
		leader(x);
		return weight.at(x);
	}

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
	vector<ll> weight;
};
