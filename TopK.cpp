template<class T, class Compare = less<T>>
class TopK{
public:
    int k;
    multiset<T, Compare> st_top, st_bottom;
    T sum_stTop = 0;

    TopK(int K) : k(K){};
    TopK(int K, vector<T> Vec);
    void add(T val);
    void erase(T val);
    T getKthVal();      //小さい方からk番目の数
    T getKthSum();      //小さい方からk番目までの合計
    int getSize();
};

template<class T, class Compare>
TopK<T, Compare>::TopK(int K, vector<T> Vec){
    k = K;
    sort(Vec.begin(), Vec.end(), Compare());
    for(int i = 0; i < size(Vec); ++i){
        if(i < k){
            st_top.emplace(Vec.at(i));
            sum_stTop += Vec.at(i);
        }else{
            st_bottom.emplace(Vec.at(i));
        }
    }
}

template<class T, class Compare>
void TopK<T, Compare>::add(T val){
    st_top.emplace(val);
    sum_stTop += val;
    if(size(st_top) > k){
        auto itr = st_top.end();
        itr--;
        st_bottom.emplace(*itr);
        sum_stTop -= *itr;
        st_top.erase(itr);
    }
}

template<class T, class Compare>
void TopK<T, Compare>::erase(T val){
    if(st_bottom.find(val) == st_bottom.end()){
        //topから削除
        auto itr = st_top.find(val);
        assert(itr != st_top.end());
        st_top.erase(itr);
        sum_stTop -= val;
        if(size(st_bottom) > 0){
            itr = st_bottom.begin();
            st_top.emplace(*itr);
            sum_stTop += *itr;
            st_bottom.erase(itr);
        }
    }else{
        //bottomから削除
        auto itr = st_bottom.find(val);
        assert(itr != st_bottom.end());
        st_bottom.erase(itr);
    }
}

template<class T, class Compare>
T TopK<T, Compare>::getKthVal(){
    assert(size(st_top) == k);
    auto itr = st_top.end();
    itr--;
    return *itr;
}

template<class T, class Compare>
T TopK<T, Compare>::getKthSum(){
    return sum_stTop;
}

template<class T, class Compare>
int TopK<T, Compare>::getSize(){
    return size(st_top) + size(st_bottom);
}
