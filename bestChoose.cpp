using P = pair<ll, ll>;
ll bestChoose(const vector<P>& cv, ll maxCost){ //[cost, value]
    ll inf = 1LL << 60;
    vector<ll> dp(maxCost + 1, -inf);
    dp.at(0) = 0;
    for(int i = 0; i < SIZE(cv); ++i){
        auto [c, v] = cv.at(i);
        vector<ll> nxtDp = dp;
        for(int j = 0; j <= maxCost; ++j){
            if(dp.at(j) == -inf) continue;
            if(j + c <= maxCost) chmax(nxtDp.at(j + c), dp.at(j) + v);
        }
        dp = nxtDp;
        //show(dp);
    }
    ll ans = -inf;
    for(const auto& e : dp) chmax(ans, e);
    return ans;
}
