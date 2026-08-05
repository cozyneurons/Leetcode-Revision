class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return {};
        sort(nums.begin(),nums.end());
        vector<int> dp (n,1);
        vector<int> parent(n,-1);
        int max_len = 1;
        int max_idx = 0;
        for (int i = 1; i<n; i++)
        {
            for (int j = 0; j<i; j++)
            {
                if (nums[i]%nums[j]==0)
                {
                    if (dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i]>max_len)
            {
                max_len = dp[i];
                max_idx = i;
            }
        }
        int curr = max_idx;
        vector<int> result;
        while(curr!=-1)
        {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        return result;
    }
};
