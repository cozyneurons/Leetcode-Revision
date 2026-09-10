class Solution {
private:
    int ans;
    void dfs(int n,int m,int start_row,int start_col,int end_row,int end_col,
            int non_obstacles,int count, vector<vector<int>>& grid)
    {
        if (end_row == start_row && end_col == start_col && count==non_obstacles+2)
        {
            ans++;
            return;
        }
        // traverse in saare directions 
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        for (int i = 0; i<4; i++)
        {
            int new_row = start_row + dr[i];
            int new_col = start_col + dc[i];
            // check validity of new rows and columns
            if (new_row>=0 && new_row<n && new_col>=0 && new_col<m 
                && grid[new_row][new_col]!=-1)
            {
                // Store original value (0 or 2) and mark as visited (-1)
                int temp = grid[new_row][new_col];
                grid[new_row][new_col] = -1;   
                dfs(n,m,new_row,new_col,end_row,end_col,non_obstacles,count+1,grid);   
                // Backtrack: restore the original value
                grid[new_row][new_col] = temp;
            }   
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int start_row = 0;
        int start_col = 0;
        int end_row = 0;
        int end_col = 0;
        int non_obstacles = 0;
        int n = grid.size();
        int m = grid[0].size();
        ans = 0;
        // O(m*n)
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (grid[i][j]==1)
                {
                    start_row = i;
                    start_col = j;
                }
                else if (grid[i][j]==2)
                {
                    end_row = i;
                    end_col = j;
                }
                else if (grid[i][j]==0)
                {
                    non_obstacles++;
                }
            }
        }
        // Mark the start cell as visited by temporarily making it an obstacle
        grid[start_row][start_col] = -1; 
        dfs(n,m,start_row,start_col,end_row,end_col,non_obstacles,1,grid);
        // roam around to reach the end (2);
        return ans;
    }
};