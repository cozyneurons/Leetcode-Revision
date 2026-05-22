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
    bool isCompleteTree(TreeNode* root) 
    {
        int nodes = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
                nodes++;
            }
            if (curr->right)
            {
                q.push(curr->right);
                nodes++;
            }
        }
        vector<int> ans(nodes,0);
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,1});
        while(!stk.empty())
        {
            auto it = stk.top();
            TreeNode* curr = it.first;
            int index = it.second;
            if (index>nodes) return false;
            ans[index-1] = curr->val;
            stk.pop();
            if (curr->left) stk.push({curr->left,index*2});
            if (curr->right) stk.push({curr->right,index*2 + 1});
        }
        for(int i = 0; i<nodes; i++)
        {
            if (ans[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};
