template<class T>
class Compression{
public:
    bool updated = false;
    map<T, int> mp;
    vector<T> original;

    Compression<T>(){};
    Compression<T>(const vector<T>& vec);
    void add(T x);
    void update();
    int getIdx(T val);
    vector<int> getIdx(const vector<T>& vec);
};

template<class T>
Compression<T>::Compression(const vector<T>& vec){
    for(const auto& e : vec) add(e);
}

template<class T>
void Compression<T>::add(T x){
    updated = false;
    mp[x] = 0;
}

template<class T>
void Compression<T>::update(){
    if(updated) return;
    original.clear();
    int idx = 0;
    for(auto&& [e, f] : mp){
        f = idx++;
        original.push_back(e);
    }
    updated = true;
}

template<class T>
int Compression<T>::getIdx(T val){
    update();
    return mp[val];
}

template<class T>
vector<int> Compression<T>::getIdx(const vector<T>& vec){
    update();
    vector<int> result(size(vec));
    for(int i = 0; i < size(vec); ++i){
        result.at(i) = getIdx(vec.at(i));
    }
    return result;
}
