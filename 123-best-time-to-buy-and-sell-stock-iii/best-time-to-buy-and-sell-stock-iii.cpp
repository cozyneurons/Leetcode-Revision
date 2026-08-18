class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp (n+1,vector<int>(5,0));
        for (int ind = n-1; ind>=0; ind--)
        {
            for (int tranNo = 0; tranNo<4; tranNo++)
            {
                int profit;
                if (tranNo%2==0)
                {
                    profit = max (-prices[ind]+dp[ind+1][tranNo+1],dp[ind+1][tranNo]);
                }
                else 
                {
                    profit = max (prices[ind]+dp[ind+1][tranNo+1],dp[ind+1][tranNo]);
                }
                dp[ind][tranNo] = profit;
            }
        }
        return dp[0][0];
    }
};