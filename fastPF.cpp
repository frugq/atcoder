map<ll, ll> fastPF(ll n){
    static bool init = true;
    static ll maxN = 1123456;
    static vector<ll> div(maxN, -1);
    if(init){
        init = false;
        for(ll i = 2; i < maxN; ++i){
            if(div.at(i) == -1){
                div.at(i) = i;
                for(ll j = 2 * i; j < maxN; j += i){
                    div.at(j) = i;
                }
            }
        }
    }

    map<ll, ll> result;
    while(n > 1){
        result[div.at(n)]++;
        n /= div.at(n);
    }
    return result;
}
