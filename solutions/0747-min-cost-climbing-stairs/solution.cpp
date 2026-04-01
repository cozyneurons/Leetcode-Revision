class Solution {
private:
    int mincost(vector<int>& cost,vector<int>& dp,int index)
    {
        if (index<=1) return 0;
        if (dp[index]!=-1) return dp[index];
        int left = mincost(cost,dp,index-1) + cost[index-1];
        int right = mincost(cost,dp,index-2) + cost[index-2];
        dp[index] = min(left,right);
        return min(left,right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        int ans = mincost(cost,dp,n);
        return ans;
    }
};
