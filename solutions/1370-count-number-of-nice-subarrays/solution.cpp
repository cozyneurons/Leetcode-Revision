class Solution {
int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) 
        {
            sum += nums[r];
            while (sum > k) 
            {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i]%2==0) nums[i]=0;
            else nums[i] = 1;
        }
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
