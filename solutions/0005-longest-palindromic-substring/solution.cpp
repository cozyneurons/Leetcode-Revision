class Solution {
private:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        return dp[i][j] = 0;
    }
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool haakyaa = isPalindrome(i, j, s, dp);
                if (haakyaa)
                {
                    if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
