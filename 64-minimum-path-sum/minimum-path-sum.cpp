class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 200000));
        int pathSum = 0;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (i==0 && j==0) dp[i][j] = matrix[i][j];
                else if (j==0)
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][j]+matrix[i][j]);
                }
                else if (i==0)
                {
                    // khaali left se aayega
                    dp[i][j] = min(dp[i][j],dp[i][j-1]+matrix[i][j]);
                }
                else
                {
                    // dono side se aayega
                    dp[i][j] = min(dp[i][j],min(dp[i][j-1]+matrix[i][j],dp[i-1][j]+matrix[i][j]));
                }
            }
        }
        return dp[n-1][m-1];
    }
};