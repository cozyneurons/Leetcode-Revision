class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        int presum = 0;
        int postsum = 0;
        for (int i = 1; i<n; i++)
        {
            presum += nums[i-1];
            left[i] = presum;
        }
        for (int i = n-1; i>=1; i--)
        {
            postsum += nums[i];
            right[i-1] = postsum;
        }
        for (int i = 0; i<n; i++)
        {
            if (left[i]==right[i]) return i;
        }
        return -1;
    }
};
