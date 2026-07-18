class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) 
    {
        int n = nums.size();
        long long ans = 0;
        long long m = 0;
        long long r = 0;
        for (int i = 0; i<n; i++)
            {
                if (nums[i]<a)
                {
                    ans += m + r;
                }
                else if (nums[i]>b)
                {
                    r++;
                }
                else
                {
                    ans += r;
                    m++;
                }
            }
        long long MOD = 1000000007;
        return ans%MOD;
    }
};
