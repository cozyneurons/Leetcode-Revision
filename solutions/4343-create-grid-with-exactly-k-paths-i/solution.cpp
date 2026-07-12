class Solution {
private:
    int paths(vector<string>& grid, int m, int n, int k)
    {
        if (grid[0][0]=='#' || grid[m-1][n-1]=='#') return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for (int i = 0; i<m; i++)
            {
                for (int j = 0; j<n; j++)
                    {
                        if (grid[i][j]=='#') dp[i][j] = 0;
                        else
                        {
                            if (i>0) dp[i][j] += dp[i-1][j];
                            if (j>0) dp[i][j] += dp[i][j-1];
                        }
                    }
            }
        return dp[m-1][n-1];
    }
    bool dfs(int index, vector<string>& grid, int m, int n, int k)
    {
        int right_now = paths(grid,m,n,k);
        if (right_now==k) return true;
        if (right_now<k) return false;
        for (int j = index; j<m*n-1; j++)
            {
                int r = j/n;
                int c = j%n;
                if (r==0 && c==0) continue;
                grid[r][c] = '#';
                if (dfs(j+1,grid,m,n,k)) return true;
                grid[r][c] = '.';
            }
        return false;
    }
public:
    vector<string> createGrid(int m, int n, int k) 
    {
        vector<string> grid(m,string(n,'.'));
        int maxi = paths(grid,m,n,k);
        if (maxi < k) return {};
        if (maxi==k) return grid;
        if (dfs(1,grid,m,n,k)) return grid;
        return {};
    }
};
