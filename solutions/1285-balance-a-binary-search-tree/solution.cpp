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
    vector<int> temp;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        if (root->left) inorder(root->left);
        temp.push_back(root->val);
        if (root->right) inorder(root->right);
    }
    TreeNode* buildTree(int low, int high)
    {
        //1,2,3,4
        if (low>high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode* node = new TreeNode(temp[mid]);
        node->left = buildTree(low,mid-1);
        node->right = buildTree(mid+1,high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        if (!root) return NULL;
        inorder(root);
        int n = temp.size();
        TreeNode* Asliroot = buildTree(0,n-1);
        return Asliroot;
    }
};
