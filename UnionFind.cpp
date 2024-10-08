struct Node{
    int id;
    int par;
    int size;
    set<int> st;
};

class UnionFind{
public:
    vector<Node> nodes;
    UnionFind(int n) :nodes(n){
        for(int i = 0; i < n; ++i){
            nodes.at(i).id = i;
            nodes.at(i).par = i;
            nodes.at(i).size = 1;
            nodes.at(i).st.emplace(i);
        }
    };

    int root(int n){
        if(nodes.at(n).par == n) return n;

        int r = root(nodes.at(n).par);
        nodes.at(n).par = r;
        return r;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    void merge(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        if(nodes.at(x).size < nodes.at(y).size) swap(x, y);

        //x <- yでマージする
        for(const auto& e : nodes.at(y).st){
            nodes.at(x).st.emplace(e);
        }
        nodes.at(y).par = x;
        nodes.at(x).size += nodes.at(y).size;
    }

    int size(int n){
        return nodes.at(root(n)).size;
    }
};
