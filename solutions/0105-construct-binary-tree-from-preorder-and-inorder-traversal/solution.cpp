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
    unordered_map <int,int> inorder_map;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        
        for (int i=0; i<inorder.size(); i++)
        {
            inorder_map[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1) ; 
    }
    TreeNode* build(vector<int> &preorder, int low, int high)
    {
        if (low>high) return nullptr;
        int rootval = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootval);
        int mid = inorder_map[rootval];
        root->left = build(preorder,low,mid-1);
        root->right = build(preorder,mid+1,high);
        return root;
    }
};
