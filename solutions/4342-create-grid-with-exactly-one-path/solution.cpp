class Solution {
public:
    vector<string> createGrid(int m, int n) 
    {
        vector<string> grid (m, string(n,'#'));

        if (m==1)
        {
            for (int i = 0; i<n; i++)
            {
                grid[0][i] = '.';
            }
        }
        else if (n==1)
        {
            for (int i = 0; i<m; i++)
            {
                grid[i][0] = '.';
            }
        }
        else
        {
            for (int j = 0; j<n-1; j++)
            {
                grid[0][j] ='.';
            }
            for (int k = 0; k<m; k++)
            {
                grid[k][n-2] = '.';
            }
            grid[m-1][n-1] = '.';
        }
        return grid;
    }
};
