class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int ans = INT_MAX;
        if (n==1)
        {
            if (nums[0]>=target) return 1;
            else return 0;
        }
        int i = 0;
        int j = 0;
        long long current_sum = 0;
        while(i<n && j<n)
        {
            current_sum+=nums[j];
            while (current_sum>=target)
            {
                ans = min (ans, j-i+1);
                current_sum -= nums[i];
                i++;
            }
            j++;
        }
        if (ans==INT_MAX) return 0;
        return ans;
    }
};
