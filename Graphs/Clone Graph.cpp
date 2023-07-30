/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node *cloneGraphRecur(Node *node, unordered_map<int, Node*> &uMap) {
        if(node == nullptr) return nullptr;
        Node *np = new Node(node -> val);
        uMap[node -> val] = np;
        for(Node *nptr : node -> neighbors) {
            if(uMap.find(nptr -> val) == uMap.end()) {
                Node *nrp = cloneGraphRecur(nptr, uMap);
            }
            np -> neighbors.push_back(uMap[nptr -> val]);
        }
        return np;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> uMap;
        return cloneGraphRecur(node, uMap);
    }
};