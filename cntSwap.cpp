ll cntSwap(const vector<ll>& v){
	int n = size(v);
	vector<tuple<ll, int>> vec(n);
    vector<int> vec2(n);
	for(int i = 0; i < n; ++i){
		vec.at(i) = make_tuple(v.at(i), i);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n; ++i){
		vec2.at(get<1>(vec.at(i))) = i;
	}
    
	ll result = 0;
	fenwick_tree<int> fw(n);
	for(int i = 0; i < n; ++i){
		ll tmpans = i - fw.sum(0, vec2.at(i));
		result += tmpans;
		fw.add(vec2.at(i), 1);
	}
	return result;
}
