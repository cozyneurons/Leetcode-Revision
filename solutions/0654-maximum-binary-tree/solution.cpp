class Solution {
public:
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if(left>right) return nullptr;
        int maxi = nums[left];
        int idx = left;

        for(int i = left; i <= right; i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = build(nums, left, idx - 1);
        root->right = build(nums, idx + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return build(nums,0,nums.size()-1);
    }
};
