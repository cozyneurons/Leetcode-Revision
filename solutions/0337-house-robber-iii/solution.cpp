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
    // Returns a pair: {max if root is robbed, max if root is not robbed}
    vector<int> dfs(TreeNode* node) {
        if (!node) 
        {
            return {0, 0};
        }
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        //node lelo
        int lelo = node->val + left[1] + right[1];
        //node mat lo
        int mat_lo = max(left[0],left[1]) + max(right[0],right[1]);
        return {lelo,mat_lo};
    }
public:
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};
