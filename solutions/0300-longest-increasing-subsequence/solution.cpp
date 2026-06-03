class Solution {
private:
    vector<vector<int>> dp;
    int recurr(int i, int prevIndex, vector<int>& nums)
    {
        if (i >= nums.size()) return 0;
        if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];
        int dontPick = recurr(i + 1, prevIndex, nums);
        int pick = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex])
        {
            pick = 1 + recurr(i + 1, i, nums);
        }
        return dp[i][prevIndex + 1] = max(pick, dontPick);
    }
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));
        return recurr(0, -1, nums);
    }
};
