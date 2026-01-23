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
    bool isBalanced(TreeNode* root) 
    {
        if (root==nullptr) return true;
        int lh = Height(root->left);
        int rh = Height(root->right);
        if (abs(lh-rh)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int Height(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int lh = Height(root->left);
        int rh = Height(root->right);
        return 1+max(lh,rh);
    }
};
