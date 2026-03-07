class Solution {
private:
    int findSum(vector<int>& nums, int divisor)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i<n; i++)
        {
            sum += (nums[i]+divisor-1)/divisor;
        }
        return sum;
    } 
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int low = 1;
        int high = max_val;
        int ans = 1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int sum = findSum(nums,mid);
            if (sum<=threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
