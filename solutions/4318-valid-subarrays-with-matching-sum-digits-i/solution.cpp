class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) 
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i<n; i++)
        {
            long long sum = 0;
            for (int j = i; j<n; j++)
            {
                sum+=nums[j];
                long long k = sum;
                while (k>=10)
                {
                    k/=10;
                }
                if (k==x && sum%10==x) ans++;
            }
        }
        return ans;
    }
};
