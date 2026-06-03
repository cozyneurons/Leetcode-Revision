class Solution {
private:
    vector<vector<int>> dp;
    int recurr(int i, vector<int>& coins, int amount)
    {
        if (amount == 0) return 1;
        if (i >= coins.size() || amount < 0) return 0;
        if (dp[i][amount] != -1) return dp[i][amount];
        int tk = recurr(i, coins, amount - coins[i]); // wahi sikka fir se le liya
        int dtk = recurr(i + 1, coins, amount); // is sikke ko ignore kar diya
        return dp[i][amount] = tk + dtk;
    }
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));
        long long ans = recurr(0, coins, amount);
        return ans;
    }
};
    

