class Solution {
private:
    bool dfs(int row, int col, int parentRow, int parentCol,
             vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        visited[row][col] = 1;
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            
            if(newrow >= 0 && newrow < m &&
               newcol >= 0 && newcol < n &&
               grid[newrow][newcol] == grid[row][col]) {
                
                if(!visited[newrow][newcol]) {
                    if(dfs(newrow, newcol, row, col, grid, visited))
                        return true;
                }
                else if(newrow != parentRow || newcol != parentCol) {
                    return true;
                }
            }
        }
        
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(dfs(i, j, -1, -1, grid, visited))
                        return true;
                }
            }
        }
        
        return false;
    }
};

