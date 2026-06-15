class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }
        for (int j = 1; j < n; j++) 
        {
            for (int k = 0; k < m; k++)  
            {
                int leftup = matrix[j][k];
                if (k > 0) leftup += prev[k - 1];
                else leftup += 1e9;
                int rightup = matrix[j][k];
                if (k < m - 1) rightup += prev[k + 1];
                else rightup += 1e9;
                int straightup = prev[k] + matrix[j][k];
                curr[k] = min(straightup, min(leftup, rightup));
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for (int k = 0; k < m; k++)
        {
            ans = min(ans, prev[k]);
        }
        return ans;
    }
};
