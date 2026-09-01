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
    int ans;
    void dfs(TreeNode* root)
    {
        if (!root) return;
        if (root->left && !root->left->left && !root->left->right) ans+=root->left->val;
        dfs(root->left);
        dfs(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};