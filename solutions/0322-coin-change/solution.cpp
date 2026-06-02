class Solution {
private:
    vector<vector<int>> dp;
    int recurr(int i, vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        if (i >= coins.size() || amount < 0) return 1e9;
        if (dp[i][amount] != -1) return dp[i][amount];
        int tk = 1 + recurr(i, coins, amount - coins[i]); // wahi sikka fir se le liya
        int dtk = recurr(i + 1, coins, amount); // is sikke ko ignore kar diya
        return dp[i][amount] = min(tk, dtk);
    }
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));
        int ans = recurr(0, coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }
};
