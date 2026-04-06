class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size();
        while (n!=1)
        {
            vector<int> newNums(n-1);
            for (int i = 0; i<n-1; i++)
            {
                newNums[i] = (nums[i] + nums[i+1]) % 10;
            }
            n = n - 1;
            nums = newNums;
        }
        return nums[0];
    }
};
