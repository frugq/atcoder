template<class T>
class CumulativeSum{
private:
    int n;
    vector<T> sumVec;
public:
    CumulativeSum(){}
    CumulativeSum(const vector<T> Vec){
        n = SIZE(Vec);
        sumVec.resize(n + 1, 0);
        for(int i = 0; i < n; ++i){
            sumVec.at(i + 1) += sumVec.at(i) + Vec.at(i);
        }
    }

    T getSum(int l, int r){ //[l, r)
        assert(0 <= l && l <= n);
        assert(0 <= r && r <= n);
        return sumVec.at(r) - sumVec.at(l);
    }
};

template<class T>
class CumulativeSum2{
public:
    int h, w;
    vector<vector<T>> sumVec;
public:
    CumulativeSum2(){}
    CumulativeSum2(const vector<vector<T>> Vec){
        h = SIZE(Vec);
        w = SIZE(Vec.at(0));
        sumVec.resize(h + 1, vector<T>(w + 1, 0));
        for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j){
            sumVec.at(i + 1).at(j + 1) = Vec.at(i).at(j);
        }
        for(int i = 0; i < h; ++i) for(int j = 0; j < w + 1; ++j){
            sumVec.at(i + 1).at(j) += sumVec.at(i).at(j);
        }
        for(int j = 0; j < w; ++j) for(int i = 0; i < h + 1; ++i){
            sumVec.at(i).at(j + 1) += sumVec.at(i).at(j);
        }
    }

    T getSum(int li, int ri, int lj, int rj){ //[l, r)
        assert(0 <= li && li <= ri && ri <= h);
        assert(0 <= lj && lj <= rj && rj <= w);
        return sumVec.at(ri).at(rj) - sumVec.at(li).at(rj) - sumVec.at(ri).at(lj) + sumVec.at(li).at(lj);
    }
};
