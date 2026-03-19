class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 2) return n;
        int i = 0;
        int j = 0;
        while (j < n)
        {
            int val = nums[j];
            nums[i++] = val;
            j++;
            if (j < n && nums[j] == val)
            {
                nums[i++] = val;
                j++;
            }
            while (j < n && nums[j] == val)
            {
                j++;
            }
        }
        return i;
    }
};
