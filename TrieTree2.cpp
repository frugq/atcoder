using S = char;
struct Node{
	int id;
	S val;
	ll cnt = 0;
	ll sumCnt = 0;
	map<S, int> nxtId;
};

ostream& operator<<(ostream& os, const Node& x) {
	os  << "id=" << x.id << " val=" << x.val << " cnt=" << x.val << " sumCnt=" << x.sumCnt << " nxtId=";
	for (const auto& e : x.nxtId) {
		os << "{" << e.first << "," << e.second << "} ";
	}
	os << endl;
	return os;
}

class TrieTree {
public:
	vector<Node> nodes;

	TrieTree(S initNode) {
		nodes.clear();
		nodes.push_back(Node(0, initNode, 0, 0));
	}

	int addVec(const vector<S>& vec) {
		int nowId = 0;
		for (const auto& e : vec) {
			nodes.at(nowId).sumCnt++;
			if (nodes.at(nowId).nxtId.count(e) == 0) {
				int id = SIZE(nodes);
				nodes.at(nowId).nxtId[e] = id;
				nodes.push_back(Node(id, e, 0, 0));
				nowId = id;
			}
			else {
				nowId = nodes.at(nowId).nxtId.at(e);
			}
		}
		nodes.at(nowId).cnt++;
		nodes.at(nowId).sumCnt++;
		return nowId;
	}

	void eraseVec(const vector<S>& vec) {
		if (getId(vec) == -1) return;

		int nowId = 0;
		for (const auto& e : vec) {
			nodes.at(nowId).sumCnt--;
			nowId = nodes.at(nowId).nxtId.at(e);
		}
		nodes.at(nowId).cnt--;
		nodes.at(nowId).sumCnt--;
	}

	//存在しない場合は-1を返す
	int getId(const vector<S>& vec) {
		int nowId = 0;
		for (const auto& e : vec) {
			if (nodes.at(nowId).nxtId.count(e) == 0) return -1;
			nowId = nodes.at(nowId).nxtId.at(e);
		}
		return nowId;
	}


	friend ostream& operator<<(ostream& os, const TrieTree& x) {
		os << endl;
		for (const auto& e : x.nodes) {
			os << e;
		}
		return os;
	}
};

vector<char> toCharVec(string s) {
	vector<char> result;
	for (const auto& e : s) result.push_back(e);
	return result;
}
