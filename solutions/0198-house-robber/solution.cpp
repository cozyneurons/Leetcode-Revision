class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = nums[0];
        if(n==1) return ans;
        if(n==2) return max(nums[0],nums[1]);
        int prev2 = nums[0];
        int prev = max(nums[0],nums[1]);
        int pick = 0;
        int dontpick = 0;
        for (int i = 2; i<n; i++)
        {
            if ((i-2)>=0) pick = nums[i] + prev2;
            if ((i-1)>=0) dontpick = 0 + prev;
            ans = max (pick,dontpick);
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};
