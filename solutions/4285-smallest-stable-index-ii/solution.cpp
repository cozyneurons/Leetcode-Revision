class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> suffixMin = nums;
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMin[i] = min(suffixMin[i], suffixMin[i + 1]);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            int instability = maxi - suffixMin[i];
            if (instability <= k) return i;
        }
        return -1;
    }
};
