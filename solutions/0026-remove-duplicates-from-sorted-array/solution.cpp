class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;

        int i = 0;
        int j = 0;

        while (j < nums.size() - 1)
        {
            if (nums[j] == nums[j+1])
            {
                j++;
            }
            else
            {
                i++;
                nums[i] = nums[j+1];
                j++;
            }
        }

        return i + 1;
    }
};
