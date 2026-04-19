class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0, right = n - 1;
        long long sum = 0;
        while (left < right)
        {
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};
