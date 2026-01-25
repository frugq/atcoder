//偏角ソート
using P = pair<ll, ll>;

bool comp(P a, P b) {
	bool isLowerA = !(a.second > 0 || (a.first >= 0 && a.second == 0));
	bool isLowerB = !(b.second > 0 || (b.first >= 0 && b.second == 0));

	if (isLowerA != isLowerB) return isLowerA < isLowerB;
	return a.first * b.second - a.second * b.first > 0;
}

bool same(P a, P b) {
	bool isLowerA = !(a.second > 0 || (a.first >= 0 && a.second == 0));
	bool isLowerB = !(b.second > 0 || (b.first >= 0 && b.second == 0));

	if (isLowerA != isLowerB) return false;
	return a.first * b.second - a.second * b.first == 0;
}
