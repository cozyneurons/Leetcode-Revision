class Solution {
private:
    int f (int idx, vector<int>& arr,int d, vector<int>& dp)
    {
        int n = arr.size();
        if (idx==n) return 0;
        if (dp[idx]!=-1) return dp[idx];
        // do all possible combinations on this index
        // dp[i] = 1 + max(dp[j]);
        int maxi1 = 0;
        for (int j = min(n-1,idx+1); j<=min(idx+d,n-1); j++)
        {
            if ( arr[j]>=arr[idx] ) break;
            maxi1 = max(maxi1,f(j,arr,d,dp));
        }
        int maxi2 = 0;
        for (int j = max(0,idx-1); j>=max(idx-d,0); j--)
        {
            if ( arr[j]>=arr[idx] ) break;
            maxi2 = max(maxi2,f(j,arr,d,dp));
        }
        return dp[idx] = 1 + max(maxi1,maxi2);
    }
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = 1;
        for (int i = 0; i<n; i++)
        {
            ans = max (ans, f(i,arr,d,dp));
        }
        return ans;
    }
};
