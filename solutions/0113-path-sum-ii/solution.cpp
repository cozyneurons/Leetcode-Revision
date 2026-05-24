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

 //vactor

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root,targetSum,ans,temp);
        return ans;
    }
    void dfs(TreeNode* root, int neededSum,vector<vector<int>>& ans, vector<int>& temp)
    {
        if (!root) return ;
        temp.push_back(root->val);
        if (root->left==NULL && root->right==NULL)
        {
            if (root->val==neededSum) 
            {
                ans.push_back(temp);
            }
        }
        dfs(root->left, neededSum - root->val,ans,temp);
        dfs(root->right,neededSum - root->val,ans,temp);  
        temp.pop_back();
    }
};


