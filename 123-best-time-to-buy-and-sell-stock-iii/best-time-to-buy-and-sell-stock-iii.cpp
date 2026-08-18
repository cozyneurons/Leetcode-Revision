class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> after(5,0);
        vector<int> curr(5,0);
        for (int ind = n-1; ind>=0; ind--)
        {
            for (int tranNo = 0; tranNo<4; tranNo++)
            {
                int profit;
                if (tranNo%2==0)
                {
                    profit = max (-prices[ind]+after[tranNo+1],after[tranNo]);
                }
                else 
                {
                    profit = max (prices[ind]+after[tranNo+1],after[tranNo]);
                }
                curr[tranNo] = profit;
            }
            after = curr;
        }
        return curr[0];
    }
};