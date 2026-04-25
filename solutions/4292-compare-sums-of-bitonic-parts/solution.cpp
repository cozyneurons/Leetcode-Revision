class Solution {
public:
    int compareBitonicSums(vector<int>& nums) 
    {
        int n = nums.size();
        int peak = -1;
        for (int i = 1; i<n-1; i++)
            {
                if (nums[i]>nums[i+1] && nums[i]>nums[i-1])
                {
                    peak = i;
                }
            }
        long long leftsum = 0;
        long long rightsum = 0;
        for (int i = 0; i<n; i++)
            {
                if (i<peak)
                {
                    leftsum+=nums[i];
                }
                else if (i==peak)
                {
                    leftsum+=nums[i];
                    rightsum+=nums[i];
                }
                else
                {
                    rightsum+=nums[i];
                }
            }
        if (leftsum > rightsum) return 0;
        else if (rightsum > leftsum) return 1;
        return -1;
    }
};
