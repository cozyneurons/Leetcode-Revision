class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 1;
        int ans = INT_MIN;
        for (int i = 1; i<n; i++)
        {
            if (nums[i]>nums[i-1])
            {
                count++;
                ans = max(count,ans);
            }
            else count = 1;
        }
        return ans == INT_MIN ? 1 : ans;
    }
};
