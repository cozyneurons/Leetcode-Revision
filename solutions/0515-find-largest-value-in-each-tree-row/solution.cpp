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
    vector<int> largestValues(TreeNode* root) 
    {
        if(!root) return {};
        
        int n = 0;
        
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,0});
        
        while(!stk.empty())
        {
            TreeNode* curr = stk.top().first;
            int level = stk.top().second;
            stk.pop();
            
            n = max(n,level+1);
            
            if(curr->right)
            {
                stk.push({curr->right,level+1});
            }
            
            if(curr->left)
            {
                stk.push({curr->left,level+1});
            }
        }
        
        vector<int> ans(n,INT_MIN);
        
        dfs(root,0,ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int level, vector<int>& ans)
    {
        if(!root) return;
        
        int maxi = max(ans[level],root->val);
        ans[level] = maxi;
        
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
};
