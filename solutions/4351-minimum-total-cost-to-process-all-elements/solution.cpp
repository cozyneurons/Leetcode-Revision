class Solution {
public:
    int minimumCost(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        long long res = k;
        long long operation_cost = 1;
        long long ans = 0;
        for (int i = 0; i<n; i++)
            {
                if (res<nums[i])
                    {
                        long long diff = nums[i] - res;
                        long long need = diff/k;
                        if (diff%k!=0) need++;

                        long long cost = (long long)((__int128)need*operation_cost + (__int128)need*(need-1)/2)%MOD;
                        ans = (ans + cost)%MOD;
                        operation_cost = (operation_cost + need)%MOD;
                        res += need*1LL*k;
                    }
                res -= nums[i];
            }
        return ans;
    }
};
