class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++) matrix[i][i] = 0;
    for (auto x : times)
    {
        int row = x[0] - 1;
        int col = x[1] - 1;
        int weight = x[2];
        matrix[row][col] = weight;
    }
        for (int via = 0; via<n; via++)
        {
            for (int i = 0; i<n; i++)
            {
                for (int j = 0; j<n; j++)
                {
                    if (matrix[i][via] != 1e9 && matrix[via][j] != 1e9)
                    {
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++)
        {
            if (matrix[k-1][i] == 1e9) return -1;
            ans = max(ans, matrix[k-1][i]);
        }
        return ans;
    }
};
