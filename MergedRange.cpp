class MergedRange {
public:
	using Range = pair<ll, ll>;	//(R, L)順番注意、半開区間[L, R)
	const ll inf = 1LL << 60;
	set<Range> st;
	ll cnt = 0;

	MergedRange() {
		st.emplace(Range(-inf, -inf));
		st.emplace(Range(inf, inf));
	}

	void addRange(ll l, ll r) {
		auto itr = st.lower_bound(Range(l, -inf));
		ll resultL = l, resultR = r;
		while (itr != st.end()) {
			auto [nowR, nowL] = *itr;
			if (r < nowL) break;
			
			chmin(resultL, nowL);
			chmax(resultR, nowR);

			itr = st.erase(itr);
			cnt -= nowR - nowL;
		}
		st.emplace(Range(resultR, resultL));
		cnt += resultR - resultL;
	}

	void eraseRange(ll l, ll r) {//未チェック
		auto itr = st.lower_bound(Range(l, -inf));
		vector<Range> tmp;//後から追加する範囲
		while (itr != st.end()) {
			auto [nowR, nowL] = *itr;
			if (r < nowL) break;
			
			if (nowL < l) {
				tmp.push_back(Range(l, nowL));
			}
			if (r < nowR) {
				tmp.push_back(Range(nowR, r));
			}

			itr = st.erase(itr);
			cnt -= nowR - nowL;
		}
		for (const auto& e : tmp) {
			st.emplace(e);
			cnt += e.first - e.second;
		}
	}

	bool isExist(ll x) {//未チェック
		auto itr = st.lower_bound(Range(x + 1, -inf));
		if (itr != st.end()) {
			auto [nowR, nowL] = *itr;
			return nowL <= x;
		}
		else {
			return false;
		}
	}
};
ostream& operator <<(ostream& os, const MergedRange& mr) {
	for (const auto& [r, l] : mr.st) {
		if (l == -mr.inf || l == mr.inf) continue;
		os << "[" << l << "," << r << "] ";
	}
	return os;
}
