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
    void toto(TreeNode* node, int level, vector<int>& ans)
    {
        if (ans.size()==level) ans.push_back(node->val);
        if (node->left) toto(node->left, level+1,ans);
        if (node->right) toto(node->right,level+1,ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        if (!root) return 0;
        vector<int> ans;
        toto(root,0,ans);
        return ans.back();
    }
};
