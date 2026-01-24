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
    int mini = INT_MAX;
    TreeNode* prev = nullptr;
    void inorderTravelsal(TreeNode* root)
    {
        if(!root) return;
        inorderTravelsal(root->left);
        if (prev)
        {
            mini = min ( mini, root->val - prev->val);
        }
        prev = root;
        inorderTravelsal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        if(!root) return 0;
        inorderTravelsal(root);
        return mini;
    }
};
