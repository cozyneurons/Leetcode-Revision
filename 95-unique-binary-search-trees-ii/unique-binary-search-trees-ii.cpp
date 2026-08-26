class Solution {
private:
    map<pair<int,int>, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) 
        {
            vector<TreeNode*> left_bsts;
            vector<TreeNode*> right_bsts;
            if (mp.find({start,i-1})==mp.end())
            {
                left_bsts = solve(start, i - 1);
                mp[{start,i-1}] = left_bsts;
            } 
            else left_bsts = mp[{start,i-1}];
            if (mp.find({i+1,end})==mp.end())
            {
                right_bsts = solve(i + 1, end);
                mp[{i+1,end}] = right_bsts;
            } 
            else right_bsts = mp[{i+1,end}];
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