bool sumMakeable(const vector<ll>& vec, ll target){
    assert(target >= 0);
    vector<bool> dp(target + 1, false);
    dp.at(0) = true;
    for(int i = 0; i < SIZE(vec); ++i){
        vector<bool> nxtDp = dp;
        for(int j = 0; j <= target; ++j){
            if(!dp.at(j)) continue;
            if(j + vec.at(i) <= target) nxtDp.at(j + vec.at(i)) = true;
        }
        dp = nxtDp;
    }
    return dp.at(target);
}
