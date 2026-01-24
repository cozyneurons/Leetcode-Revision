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
    int count = 0;
    int value  = 0;
    void inorderTravelsal(TreeNode* root, int k)
    {
        if (!root || count>=k) return;
        inorderTravelsal(root->left,k);
        if (++count==k)
        {
            value = root->val;
            return;
        }
        if (count==k) value=root->val;
        inorderTravelsal(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        inorderTravelsal(root,k);
        return value;
    }
};
