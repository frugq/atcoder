//区間加算、最大値取得
using S = ll;

S op(S a, S b) { 
	return max(a, b);
}

S e() {	//単位元
	return -1;
}

/*S target = 0;
bool f(S x) {
	return x > target;
}*/

//segtree<S, op, e> seg(n);
// set(i, x)		a[i] <- x
// get(i)			return a[i]
// prod(l, r)		区間取得
// all_prod()		全区間取得
// max_right<f>(l)	f(op(a[l], a[l + 1], ..., a[r - 1])) = trueを満たす、最大のr
// min_left<f>(r)	f(op(a[l], a[l + 1], ..., a[r - 1])) = trueを満たす、最小のl
