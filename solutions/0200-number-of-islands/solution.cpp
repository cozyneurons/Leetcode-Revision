class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid )
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col]=1;
        queue <pair<int,int>> q;
        q.push({row,col});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        while(!q.empty())
        {
            int rowww = q.front().first;
            int colll = q.front().second;
            q.pop();
            for (int k = 0; k<4; k++)
            {
                int newrow = rowww + dr[k];
                int newcol = colll + dc[k];
                if (newrow>=0 && newcol>=0 && newrow<n && newcol<m &&
                    !visited[newrow][newcol] && grid[newrow][newcol]=='1')
                {
                    visited[newrow][newcol] = 1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n,vector<int> (m,0));
        for (int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if (!visited[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};
