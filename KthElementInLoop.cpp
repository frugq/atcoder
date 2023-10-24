template<class T>
class KthElementInLoop{
public:
    ll n = -1, loopStart = -1, loopEnd = -1, loopCycle = -1;
    vector<T> vec;
    KthElementInLoop(){}
    KthElementInLoop(const vector<T> Vec);
    bool simulate();
    T getValue(ll k);
};

template<class T>
KthElementInLoop<T>::KthElementInLoop(const vector<T> Vec){
    n = SIZE(Vec);
    vec = Vec;
    assert(simulate());
}

template<class T>
bool KthElementInLoop<T>::simulate(){
    map<T, int> val2idx;
    for(int i = 0; i < n; ++i){
        if(val2idx.count(vec.at(i))){
            loopStart = val2idx[vec.at(i)];
            loopEnd = i;
            loopCycle = loopEnd - loopStart;
            return true;
        }
        val2idx[vec.at(i)] = i;
    }
    return false;
}

template<class T>
T KthElementInLoop<T>::getValue(ll k){
    if(k < n) return vec.at(k);
    return vec.at(loopStart + (k - loopStart) % loopCycle);
}
