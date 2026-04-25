class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n = nums.size();

        int mistake = 0;
        for (int p = 0; p<n-1; p++)
        {
            if (nums[p]>nums[p+1])
            {
                mistake++;
                if (p==0)
                {
                    nums[p] = nums[p+1];
                }
                else if (p==n-2)
                {
                    nums[p+1] = nums[p];
                }
                else if (nums[p+1]>=nums[p-1])
                {
                    nums[p] = nums[p+1];
                }
                else
                {
                    nums[p+1] = nums[p];
                }

                if (mistake==2) return false;
            }
        }
        return true;
    }
};
