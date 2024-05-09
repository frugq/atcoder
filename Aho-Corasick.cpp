class Node{
public:
    char c;
    vector<int> nxt;
    int failure;
    bool isEnd;

    Node(char C){
        c = C;
        nxt.resize(26, -1);
        failure = 0;
        isEnd = false;
    }
};

class ahoCorasick{
public:
    vector<Node> nodes;
    
    ahoCorasick(){
        nodes = {Node(' ')};
    };

    void addKey(const string s){
        int now = 0;
        for(char c : s){
            int numC = c - 'a';
            if(nodes.at(now).nxt.at(numC) == -1){//nxtが存在しない
                nodes.at(now).nxt.at(numC) = SIZE(nodes);
                nodes.push_back(Node(c));
            }
            now = nodes.at(now).nxt.at(numC);
        }
        nodes.at(now).isEnd = true;
    }

    void updateFailure(){
        queue<int> que;
        que.emplace(0);
        while(!que.empty()){
            int now = que.front(); que.pop();
            for(int i = 0; i < 26; ++i){
                if(nodes.at(now).nxt.at(i) == -1) continue;
                int nxt = nodes.at(now).nxt.at(i);
                int failure = nodes.at(now).failure;
                if(nodes.at(failure).nxt.at(i) != -1){
                    nodes.at(nxt).failure = nodes.at(failure).nxt.at(i);
                }else{
                    if(nodes.at(0).nxt.at(i) != -1){
                        nodes.at(nxt).failure = nodes.at(0).nxt.at(i);
                    }else{
                        nodes.at(nxt).failure = 0;
                    }
                }
            }
        }
    }
    
    bool search(string s){
        int now = 0;
        for(char c : s){
            int numC = c - 'a';
            if(nodes.at(now).nxt.at(numC) == -1){
                now = nodes.at(now).failure;
            }else{
                now = nodes.at(now).nxt.at(numC);
            }
            if(nodes.at(now).isEnd) return true;
        }
        return false;
    }

};
