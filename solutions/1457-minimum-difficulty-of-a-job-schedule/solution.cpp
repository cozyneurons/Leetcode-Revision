class Solution {
    int doJob(vector<int>& jD,vector<vector<int>>& dp,int n, int idx, int d)
    {
        if (dp[idx][d]!=-1) return dp[idx][d];
        int maxD = jD[idx];
        if (d==1)
        {
            for (int i = idx; i<n; i++)
            {
                maxD = max(maxD,jD[i]);
            }
            return maxD;
        }

        int finalResult = INT_MAX;;
        for (int i = idx; i<=n-d; i++)
        {
            maxD = max(maxD,jD[i]);
            int result = maxD + doJob(jD,dp,n,i+1,d-1);
            finalResult = min(finalResult,result);
        }
        return dp[idx][d] = finalResult;
    }
public:
    int minDifficulty(vector<int>& jD, int d) 
    {
        int n = jD.size();

        if (n<d) return -1;
        vector<vector<int>> dp (301,vector<int>(11,-1));
        return doJob(jD,dp, n,0,d);
    }
};
