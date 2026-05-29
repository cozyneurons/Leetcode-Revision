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
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int maxi = INT_MIN;
        int ans = 0;
        while (!q.empty()) 
        {
            level++;
            int level_size = q.size();
            int current_level = 0;
            for (int i = 0; i<level_size; i++) 
            {
                TreeNode* node = q.front();
                q.pop();
                current_level+=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (current_level>maxi)
            {
                maxi = current_level;
                ans = level;
            }
        }
        return ans; 
    }
};
