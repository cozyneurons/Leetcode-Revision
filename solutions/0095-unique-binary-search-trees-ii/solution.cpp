class Solution {
private:
    vector<TreeNode*> solve(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) 
        {
            vector<TreeNode*> left_bsts = solve(start, i - 1);
            vector<TreeNode*> right_bsts = solve(i + 1, end);
            for (TreeNode* leftNode : left_bsts) 
            {
                for (TreeNode* rightNode : right_bsts) 
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};
