class Solution {
private:
    int helper(int ind, int buy , int cap, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        if (ind==prices.size()) return 0;
        if (cap==0) return dp[ind][buy][cap] = 0;
        if (dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit;
        if (buy)
        {
            profit = max (-prices[ind]+helper(ind+1,0,cap,prices,dp),helper(ind+1,1,cap,prices,dp));
        }
        else
        {
            profit = max (prices[ind]+helper(ind+1,1,cap-1,prices,dp),helper(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2,prices,dp);
    }
};
