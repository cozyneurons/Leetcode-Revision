class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int maxIndex = 0;
        for (int i = 0; i<n; i++)
        {
            if (i > maxIndex) return false;
            maxIndex = max(i + nums[i] , maxIndex);
            if (maxIndex > n) return true;
        }
        return true;
    }
};
