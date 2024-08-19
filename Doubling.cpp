class Doubling{
public:
    int _n, _log2Move = 0;
    vector<vector<int>> _nxt;//nxt[i][j] = 現在i，2^j回移動後の位置

    Doubling(const vector<int>& nxt, ll maxMove){
        _log2Move = 0;
        while(maxMove > 0) maxMove /= 2, _log2Move++;
        chmax(_log2Move, 1);
        _n = SIZE(nxt);
        _nxt.resize(_n, vector<int>(_log2Move, 0));
        for(int i = 0; i < _n; ++i){
            _nxt[i][0] = nxt[i];
        }

        for(int j = 0; j < _log2Move - 1; ++j){
            for(int i = 0; i < _n; ++i){
                _nxt[i][j + 1] = _nxt[_nxt.at(i).at(j)][j];
            }
        }
    }

    int calcPos(int pos, ll cnt){
        int result = pos;
        for(ll i = 0; i < _log2Move; ++i){
            if(cnt >> i & 1){
                result = _nxt[result][i];
            }
        }
        return result;
    }
};
