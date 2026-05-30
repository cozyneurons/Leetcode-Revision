/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue <Node*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i<n; i++)
            {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (!node->children.empty())
                {
                    vector<Node*> temp = node->children;
                    int m = temp.size();
                    for (int i = 0; i<m; i++)
                    {
                        q.push(temp[i]);
                    }
                }
            }
            ans.push_back(level);    
        }
        return ans;
    }
};
