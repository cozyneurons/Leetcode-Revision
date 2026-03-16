class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0; 
        int j = n - 1;
        int count = 0;
        while (i<j)
        {
            if (nums[i]+nums[j]<target)
            {
                count += (j-i);
                i++;
            }
            else j--;
        }
        return count;
    }
};
