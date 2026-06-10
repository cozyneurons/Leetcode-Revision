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
    void dfs(Node* luv, Node* kush, unordered_map<Node*, Node*>& mp)
    {
        for (auto neigh : luv->neighbors)
        {
            if (mp.find(neigh) == mp.end())
            {
                Node* _clone = new Node(neigh->val);
                mp[neigh] = _clone;
                kush->neighbors.push_back(_clone);
                dfs(neigh, _clone, mp);
            }
            else
            {
                kush->neighbors.push_back(mp[neigh]);
            }
        }
    }
    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        dfs(node, clone_node, mp);
        return clone_node;
    }
};
