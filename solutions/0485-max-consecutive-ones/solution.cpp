class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0 ;
        int maxi = 0 ;
        int ones = 0;
        while (i<n)
        {
            if(nums[i]==1)
            {
                ones++;
                maxi = max(maxi,ones);
            }
            else
            {
                ones = 0;
            }
            i++;
        }
        return maxi;
    }
};
