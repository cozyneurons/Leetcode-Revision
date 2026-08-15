class Solution {
private:
    int f (int i, int n, vector<int>& arr,vector<int>& dp, int k)
    {
        if (i==n) return 0;
        if (dp[i]!=-1) return dp[i];
        long long ans = INT_MIN;
        int len = 0;
        int maxi = INT_MIN;
        for (int j = i; j<min(n,k+i); j++)
        {
            len++;
            maxi = max(maxi,arr[j]);
            long long sum = len*maxi + f(j+1,n,arr,dp,k);
            ans = max (ans,sum);
        }
        return dp[i] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return f(0,n,arr,dp,k);
    }
};
