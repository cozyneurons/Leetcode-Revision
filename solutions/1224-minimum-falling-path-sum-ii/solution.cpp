class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int colmin1 = INT_MAX;
        int colmin2 = INT_MAX;
        int mincol = -1;
        for (int k = 0; k < m; k++)
        {
            if (grid[n-1][k] < colmin1)
            {
                colmin2 = colmin1;
                colmin1 = grid[n-1][k];
                mincol = k;
            }
            else if (grid[n-1][k] < colmin2)
            {
                colmin2 = grid[n-1][k];
            }
        }
        for (int j = n-2; j >= 0; j--)
        {
            int temp1 = INT_MAX;
            int temp2 = INT_MAX;
            int tempcol = -1;
            vector<int> curr(m);
            for (int k = 0; k < m; k++)
            {
                int choose;
                if (k == mincol) choose = grid[j][k] + colmin2;
                else choose = grid[j][k] + colmin1;
                curr[k] = choose;
                if (choose < temp1)
                {
                    temp2 = temp1;
                    temp1 = choose;
                    tempcol = k;
                }
                else if (choose < temp2)
                {
                    temp2 = choose;
                }
            }
            colmin1 = temp1;
            colmin2 = temp2;
            mincol = tempcol;
        }
        return colmin1;
    }
};
