class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> after(2,0);
        vector<int> curr(2,0);
        for (int i = n-1; i>=0; i--)
        {
            // holding satate
            curr[0] = max (prices[i] + after[1]-fee,after[0]);
            // not holding 
            curr[1] = max(-prices[i] + after[0],after[1]);
            after = curr;
        }
        return after[1];
    }
};
