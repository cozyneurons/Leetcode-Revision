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
 class Solution{
private:
    void dfs(TreeNode* left, TreeNode* right, int lavelsabkenikalenge)
    {
        // base condition
        if (!left || !right) return;
        if (lavelsabkenikalenge%2) 
        {
            swap(left->val,right->val);
        }
        //step 1  left ke left pe jao, right ke right pe jao
        dfs(left->left,right->right,lavelsabkenikalenge+1);
        // step 2 left ke right pe jao, right ke left pe jao
        dfs(left->right,right->left,lavelsabkenikalenge+1);
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        if (!root) return root;
        dfs(root->left, root->right, 1);
        return root;
    }
};
