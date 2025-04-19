template<class T> 
void getDupPerm(const map<T, int>& mp, vector<vector<T>>& result){
    static vector<T> vec;
    bool finished = true;
    for(const auto& [e, f] : mp){
        if(f > 0){
            finished = false;
            break;
        }
    }
    if(finished){
        result.push_back(vec);
        return;
    }
    for(const auto& [e, f] : mp) if(f > 0){
        auto copyMp = mp;
        copyMp[e]--;
        vec.push_back(e);
        getDupPerm(copyMp, result);
        vec.pop_back();
    }
}
