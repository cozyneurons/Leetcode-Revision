class Solution {
public:
    int findChampion(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> kamzor(n,0);
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (i==j) continue;
                if (grid[i][j]==1) kamzor[j]++;
                else kamzor[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++)
        {
            if (kamzor[i]==0) ans = i;
        }
        return ans;
    }
};
