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
    int pathSum(TreeNode* root, long long targetSum) 
    {
        int ans = 0;
        if (!root) return ans;

        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* curr = stk.top();
            stk.pop();
            dfs(curr,targetSum,ans);
            if (curr->left) stk.push(curr->left);
            if (curr->right) stk.push(curr->right);
        }
        return ans;
    }
    void dfs(TreeNode* root, long long neededSum, int& ans)
    {
        if (!root) return ;
        if (root->val==neededSum) ans++;

        dfs(root->left, neededSum - root->val,ans);
        dfs(root->right,neededSum - root->val,ans);  

    }
    
};
