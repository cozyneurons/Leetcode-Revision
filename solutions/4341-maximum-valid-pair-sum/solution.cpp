class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int ans = 0;
        int prefix = 0;
        for (int i = 0; i<n; i++)
        {
            prefix = max(prefix,nums[i]);
            if (i+k<n) ans = max(ans,prefix+nums[i+k]);
        }
        return ans;
    }
};
