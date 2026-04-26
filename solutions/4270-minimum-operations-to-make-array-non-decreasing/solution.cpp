class Solution {
public:
    long long minOperations(vector<int>& nums) 
    {
        long long operations = 0;
        int n = nums.size();

        if (n==1) return 0;
        int i = 0;
        int j = 1;
        while (i<n && j<n)
            {
                if (nums[j]<nums[i])
                {
                    operations += nums[i] - nums[j];
                }
                i = j;
                j++;
            }
        return operations;
    }
};
