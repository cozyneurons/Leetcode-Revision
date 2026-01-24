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
    vector<int> a;
    void inorderTravelsal(TreeNode* root, vector<int> &a)
    {
        if(!root) return ;
        inorderTravelsal(root->left, a);
        a.push_back(root->val);
        inorderTravelsal(root->right, a);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        inorderTravelsal(root1, a);
        inorderTravelsal(root2, a);
        sort(a.begin(),a.end());
        return a;
    }
};
