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
    int good;
    void dfs(TreeNode* root, int maxi)
    {
        if (!root) return;
        int value = root->val;
        if (value>=maxi)
        {
            maxi = value;
            good+=1;
        }
        if (root->left) dfs(root->left,maxi);
        if (root->right) dfs(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) 
    {
        int maxi = INT_MIN;
        good = 0;
        dfs(root,maxi);
        return good;
    }
};
