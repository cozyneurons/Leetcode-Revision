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
    unordered_map<int,TreeNode*> ump;
    unordered_set<int> st;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        for (auto& vec : descriptions)
        {
            int parent = vec[0];
            int child = vec[1];
            st.insert(child);
            int left = vec[2];
            if (ump.find(parent)==ump.end())
            {
                TreeNode* papa = new TreeNode(parent);
                ump[parent] = papa;
            }
            if (ump.find(child)==ump.end())
            {
                TreeNode* bacha = new TreeNode(child);
                // integer aur uska corresponding node ka mapping
                ump[child] = bacha;
            }
            if (left)
            {
                ump[parent]->left = ump[child];
            }
            else
            {
                ump[parent]->right = ump[child];
            }
        }
        TreeNode* root;
        for (auto& vec : descriptions)
        {
            if (st.find(vec[0])==st.end()) root = ump[vec[0]];
        }
        return root;
    }
};
