template<class T>
class CntKinds{
public:
    map<T, ll> mp;
    CntKinds(){};
    CntKinds(vector<T> vec){
        for(const auto& e : vec) mp[e]++;
    }

    void add(T x){
        mp[x]++;
    }

    void erase(T x){
        assert(mp.count(x));
        mp[x]--;
        if(mp[x] == 0) mp.erase(x);
    }

    ll getCnt(T x){
        if(mp.count(x)) return mp[x];
        return 0;
    }

    ll size(){
        return SIZE(mp);
    }
};
