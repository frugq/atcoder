int op(int x, int y){ return max(x, y);}
int e(){ return 0;}

vector<int> simpleVec(const vector<ll>& vec){
    int n = size(vec);
    vector<int> result(n);
    using Tdata = tuple<ll, int>;
    vector<Tdata> data(n);
    for(int i = 0; i < n; ++i){
        data.at(i) = make_tuple(vec.at(i), i);
    }
    sort(data.begin(), data.end(), [](Tdata x, Tdata y){
        auto [x1, x2] = x;
        auto [y1, y2] = y;
        return make_tuple(x1, -x2) < make_tuple(y1, -y2);
    });
    for(int i = 0; i < n; ++i){
        result.at(get<1>(data.at(i))) = i;
    }
    return result;
}

int lis(const vector<ll>& vec){
    int n = size(vec);
    vector<int> svec = simpleVec(vec);

    int result = 0;
    segtree<int, op, e> seg(n);
    vector<int> dp(n);
    for(int i = 0; i < n; ++i){
        dp.at(i) = seg.prod(0, svec.at(i)) + 1;
        seg.set(svec.at(i), dp.at(i));
        chmax(result, dp.at(i));
    }
    return result;
}
