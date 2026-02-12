class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue <pair<int,int>> q;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if ((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1)
                {
                    grid[i][j]=2;
                    q.push({i,j});
                }
            }
        } 
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k<4; k++)
            {
                int newrow = row + delrow[k];
                int newcol = col + delcol[k];
                if (newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]==1)
                {
                    grid[newrow][newcol]=2;
                    q.push({newrow,newcol});
                }
            }
        }
        int count = 0;
        for (int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if (grid[i][j]==1) count ++;
            }
        }
        return count;
    }
};
