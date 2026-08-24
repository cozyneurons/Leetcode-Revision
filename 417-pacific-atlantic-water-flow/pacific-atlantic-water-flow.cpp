#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // iss reachable 2d vector mei pacific bhi aata hai, atlantic bhi aata hai 
    void dfs(int r, int c, vector<vector<bool>>& reachable, const vector<vector<int>>& heights) 
    {
        reachable[r][c] = true;
        for (int i = 0; i < 4; i++) 
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                !reachable[nr][nc] && heights[nr][nc] >= heights[r][c]) 
            {
                dfs(nr, nc, reachable, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) 
        {
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }
        for (int i = 0; i < m; i++) 
        {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (pacific[i][j] && atlantic[i][j]) 
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};