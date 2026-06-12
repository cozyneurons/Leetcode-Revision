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
    void dfs(TreeNode* root, vector<vector<string>>& res, int row, int col, int height)
        {
            if(!root) return;
            res[row][col] = to_string(root->val);
            if(row == height) return;
            // In C++, powers of 2 are written using bit shifts 1 << k ka matlab hai 2^k, but yaad rakh, bit shifting only works for power of 2. for other powers, you need to use power functions
            int offset = 1 << (height - row - 1);
            dfs(root->left, res, row + 1, col - offset, height);
            dfs(root->right, res, row + 1, col + offset, height);
        }
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        if (!root) return {{}};
        int height = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            height++;
            while(sz--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        dfs(root,res,0,(n-1)/2,height);
        return res;
    }
};
