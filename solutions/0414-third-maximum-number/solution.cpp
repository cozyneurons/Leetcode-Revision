class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(), greater<int>());
        int i = 0;
        int counter = 1;
        while(i<nums.size()-1)
        {
            if (nums[i]==nums[i+1])
            {
                i++;
            }
            else
            {
                counter++;
                if (counter==3) 
                {
                    return nums[i+1];
                }
                i++;
            }
        }
        return nums[0];
    }
};
