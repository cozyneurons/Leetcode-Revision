/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int result;
    void bfs(unordered_map<int, vector<int>>& ump, int start)
    {
        queue<int> q;
        unordered_set<int> visited;  
        q.push(start);
        visited.insert(start); 
        while(!q.empty())
        {
            int size = q.size();
            bool spread = false;
            for (int i = 0; i < size; ++i)
            {
                int curr = q.front();
                q.pop();
                for (int neighbor : ump[curr])
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        spread = true;
                    }
                }
            }
            
            if (spread)
            {
                result++;
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        result = 0;
        if (!root) return 0; 
        unordered_map<int, vector<int>> ump;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();  
            if (node->left)
            {
                ump[node->val].push_back(node->left->val);
                ump[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if (node->right)
            {
                ump[node->val].push_back(node->right->val);
                ump[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        bfs(ump, start);
        return result;
    }
};
