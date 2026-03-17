class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1 || n==2) return true;
        bool upar = false;
        bool niche = false;
        int i = 0;
        while(i<n-1 && nums[i]==nums[i+1])
        {
            i++;
        }
        if (i==n-1) return true;
        if (nums[i]>nums[i+1]) niche = true;
        else upar = true;

        for (int i = 0; i<n-1; i++)
        {
            if (niche)
            {
                if (nums[i]<nums[i+1]) return false;
            }
            else if (upar)
            {
                if (nums[i]>nums[i+1]) return false;
            }
        }
        return true;
    }
};
