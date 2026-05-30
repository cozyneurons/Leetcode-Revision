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
    int maxLevelSum(TreeNode* root)
    { 
        if(root==NULL) return 0;
        int maxi = INT_MIN;
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        int ans = 0;
        while (!q.empty())
        {
            level++;
            int levelsum = 0;
            int n = q.size();
            for (int i = 0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                levelsum+=node->val;
                if (node->left!=NULL) q.push(node->left);
                if (node->right!=NULL) q.push(node->right);
                
            }
            if (levelsum>maxi)
            {
                maxi = levelsum;
                ans = level;
            }
        }
        return ans;
    }
};
