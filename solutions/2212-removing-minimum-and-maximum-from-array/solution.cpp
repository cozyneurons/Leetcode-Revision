class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 1;

        int mini = INT_MAX, maxi = INT_MIN;
        int min_index = 0, max_index = 0;
 
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < mini) { mini = nums[i]; min_index = i; }
            if (nums[i] > maxi) { maxi = nums[i]; max_index = i; }
        }

        int left  = min(min_index, max_index);
        int right = max(min_index, max_index);

        if (max_index < n/2 && min_index < n/2)
            return right + 1;

        if (max_index >= n/2 && min_index >= n/2)
            return n - left;

        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};
