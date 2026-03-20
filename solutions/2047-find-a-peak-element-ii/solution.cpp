class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n - 1;
        while (low<=high)
        {
            int mid = low + (high-low)/2;
            int maxi = 0;
            int row = 0;
            int col = mid;
            for (int i = 0; i<m; i++)
            {   
                if (mat[i][mid] > maxi)
                {
                    maxi = mat[i][mid];
                    row = i;
                }
            }
            int left = (col-1 >= 0) ? mat[row][col-1] : -1;
            int right = (col+1 < n) ? mat[row][col+1] : -1;
            if (mat[row][col] > left && mat[row][col] > right) return {row,col};
            else if (left>mat[row][col]) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};
