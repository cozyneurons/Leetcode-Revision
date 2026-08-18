class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> after(2*k + 1,0);
        vector<int> curr(2*k + 1,0);
        for (int ind = n-1; ind>=0; ind--)
        {
            for (int tranNo = 0; tranNo<(2*k); tranNo++)
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
        return after[0];
    }
};
