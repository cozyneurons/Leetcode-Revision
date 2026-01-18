class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for (int i = 0; i<nums.size(); i++)
        {
            if(nums[i]<0) nums[i]=0;
        }
        for (int i = 0; i<nums.size(); i++)
        {
            int value = abs(nums[i]);
            if (1<=value && value<=nums.size())
            {
                int index = value - 1;
                if (nums[index]>0)
                {
                    nums[index]*=-1;
                }
                else if (nums[index]==0) 
                {
                    nums[index] = -1 * (nums.size()+1);
                }
            }
        }
        for (int i = 1; i<nums.size()+1 ; i++)
        {
            if (nums[i-1]>=0) return i;
        }
        return nums.size()+1 ;
    }
};
