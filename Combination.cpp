mint comb(ll n, ll k){
	assert(n - k >= 0);
    int maxF = 1e6;
    static bool init = true;
    static vector<mint> fact(maxF, 1), invFact(maxF, 1);
    if(init){
        for(int i = 2; i < maxF; ++i){
            fact.at(i) = fact.at(i - 1) * i;
            invFact.at(i) = fact.at(i).inv();
        }
        init = false;
    }
    return fact.at(n) * invFact.at(k) * invFact.at(n - k);
}

mint homo(ll n, ll r){
    return comb(n + r - 1, r);
}
