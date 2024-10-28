//最大公約数を返す
//a,bが互いにその時，a*x + b*y = gcd(a,b)の1つの解を求められる
ll extgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll result = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return result;
}
