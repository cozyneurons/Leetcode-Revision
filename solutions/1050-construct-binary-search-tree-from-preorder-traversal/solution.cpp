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
    TreeNode* Build(vector<int>& preorder, int& i, int BOUND)
    {
        if (i>=preorder.size() || preorder[i]>BOUND) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = Build(preorder,i,root->val);
        root->right = Build(preorder,i,BOUND);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i = 0;
        return Build(preorder,i,INT_MAX);
    }
};
