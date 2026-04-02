class Solution {
private:
    int robhouse(vector<int>& nums, int start, int end)
    {
        int prev2 = 0;
        int prev = 0;
        for (int i = start; i<end; i++)
        {
            int curr = max(nums[i]+prev2,prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size()==1) return nums[0];
        return max(robhouse(nums,1,nums.size()),robhouse(nums,0,nums.size()-1));
    }
};
