class TrieTree{
private:
    void getStrings_sub(string s, int nowId, vector<string>& result){
        for(int i = 0; i < _nodes.at(nowId)._finishCnt; ++i) result.push_back(s);
        for(const auto& [nxtC, nxtId] : _nodes.at(nowId)._to){
            getStrings_sub(s + string(1, nxtC), nxtId, result);
        }
    }

    void update_sub(int nowId){
        for(const auto& [nxtC, nxtId] : _nodes.at(nowId)._to){
            update_sub(nxtId);
            _nodes.at(nowId)._sumCnt += _nodes.at(nxtId)._sumCnt;
        }
    }

public:
    struct Node{
        char _c;
        int _preId = -1;
        int _id = -1;
        map<char, int> _to;
        int _finishCnt = 0;
        int _sumCnt = 0;
    };

    vector<Node> _nodes;
    bool _updated = true;
    
    TrieTree(){
        clear();
    }

    void clear(){
        _nodes.clear();
        _nodes.push_back(Node('@'));
        _nodes.at(0)._id = 0;
        _updated = true;
    }

    void addString(const string& s){
        int nowId = 0;
        for(int i = 0; i < SIZE(s); ++i){
            if(_nodes.at(nowId)._to.count(s.at(i))){
                nowId = _nodes.at(nowId)._to[s.at(i)];
            }else{
                int nxtId = _nodes.at(nowId)._to[s.at(i)] = SIZE(_nodes);
                _nodes.push_back(Node(s.at(i)));
                _nodes.at(nxtId)._id = nxtId;
                _nodes.at(nxtId)._preId = nowId;
                nowId = nxtId;
            }
        }
        _nodes.at(nowId)._finishCnt++;
        _updated = false;
    }

    int getId(const string& s){//存在しなければ-1
        int nowId = 0;
        for(int i = 0; i < SIZE(s); ++i){
            if(_nodes.at(nowId)._to.count(s.at(i))){
                nowId = _nodes.at(nowId)._to[s.at(i)];
            }else{
                return -1;
            }
        }
        return nowId;
    }

    bool exist(const string& s){    //空文字列は含まない
        return getId(s) > 0;
    }

    string id2Prefex(int id){
        int nowId = id;
        string result = "";
        do{
            result += _nodes.at(nowId)._c;
        }while((nowId = _nodes.at(nowId)._preId) != -1);
        reverse(ALL(result));
        return result;
    }

    void deleteString(const string& s){
        _nodes.at(getId(s))._finishCnt--;
        _updated = false;
    }

    void update(){
        for(auto&& e : _nodes) e._sumCnt = e._finishCnt;
        update_sub(0);
        _updated = true;
    }

    vector<string> getStrings(){
        string str = "";
        vector<string> result;
        getStrings_sub(str, 0, result);
        return result;
    }

    int cntPrefexs(const string& s){
        if(!_updated) update();
        int nowId = getId(s);
        return _nodes.at(nowId)._sumCnt;
    }

#ifdef __LOCAL
    friend int push(const TrieTree& trie){
        for(const auto& e : trie._nodes){
            debug::push(e._id);
            debug::push(e._c);
            bool first = true;
            debug::push("[");
            for(const auto& f : e._to){
                if(!first) debug::push(",");
                first = false;
                debug::push(f);
            }
            debug::push("]");
            debug::push(e._finishCnt);
            debug::push("\n");
        }
        return 2;
    }

#endif
};
