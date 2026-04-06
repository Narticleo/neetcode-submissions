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
private:
    unordered_map<Node*, Node*> hash;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return node;
        if(hash.find(node) != hash.end())
            return hash[node];
        Node* copyNode  = new Node(node->val);
        hash[node] = copyNode;
        for(Node* neighbor : node->neighbors)
            copyNode->neighbors.push_back(cloneGraph(neighbor));
        
        return copyNode;
    }
};

