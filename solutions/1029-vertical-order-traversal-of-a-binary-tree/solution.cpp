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
public:
    map <int, map<int, multiset<int>>> mp;  
    void dfs(TreeNode* node,int row, int column)
    {
        if(!node) return;
        mp[column][row].insert(node->val);
        if (node->left) dfs(node->left,row+1,column-1);
        if (node->right) dfs(node->right,row+1,column+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        
        vector<vector<int>> ans;
        if (!root) return ans;
        dfs(root,0,0);
        for (auto &colPair : mp)
        {
            vector<int> col;
            for (auto &rowPair : colPair.second)
            {
                for (int val : rowPair.second) col.push_back(val);
            }
            ans.push_back(col);
        }
        return ans;
    }
};
