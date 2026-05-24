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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return false;
        return dfs(root,targetSum);
    }
    bool dfs(TreeNode* root, int neededSum)
    {
        // neededSum = 22
        if (!root) return false;
        if (root->left==NULL && root->right==NULL)
        {
            if (root->val==neededSum) return true;
        }
        bool left = dfs(root->left, neededSum - root->val);
        bool right = dfs(root->right,neededSum - root->val);  
        if (left || right) return true;
        return false;
    }
    
};
