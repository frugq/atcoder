mint perm(ll n, ll r){
    assert(n >= 0);
    assert(r <= n);
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
    return fact.at(n) * invFact.at(n - r);
}

mint fact(ll n){
    return perm(n, n);
}

mint comb(ll n, ll k){
	assert(n >= 0);
	assert(k >= 0);
	assert(n - k >= 0);
    return perm(n, k) / perm(k, k);
}

mint homo(ll n, ll r){
    return comb(n + r - 1, r);
}
