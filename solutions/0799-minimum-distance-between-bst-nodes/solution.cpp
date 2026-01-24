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
    TreeNode* prev = nullptr;
    int mini = INT_MAX;
    void inorderTravelsal(TreeNode* root)
    {
        if(!root) return;
        inorderTravelsal(root->left);
        if (prev) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root;
        inorderTravelsal(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) 
    {
        if (!root) return 0;
        inorderTravelsal(root);
        return mini;
    }
};
