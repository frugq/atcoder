//区間加算更新，区間最大値取得
using S = ll;
using F = ll;

S op(S x, S y) { //取得する値の計算
    return max(x, y);
}

S e() {  //単位元
    return S(0);
}

S mapping(F f, S x) { //更新　x ← mapping(f, x)
    return S(x + f);
}

F composition(F f, F g) { //合成　g(f(x))
    return F(f + g);
}

F id() {
    return F(0);
}

bool g(S x) {
    return x;
}
//set(i, x)
//get(i)
//apply(l, r, f)    区間更新
//prod(l, r)        区間取得
//all_prod()
//max_right(l)      g(op(a[l], a[l + 1], ..., a[r - 1])) = true を満たす最大のr
//min_left(r)       g(op(a[l], a[l + 1], ..., a[r - 1])) = true を満たす最小のl
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
