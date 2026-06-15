class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> firstRow(n,INT_MIN);
        vector<int> secondRow(n,INT_MIN);
        for (int i = 0; i<n; i++)
        {
            firstRow[i] = triangle[n-1][i];
        }

        for (int j = n-2; j>=0; j--)
        {
            for (int k = 0; k<triangle[j].size(); k++)
            {
                int neeche = triangle[j][k] + firstRow[k];
                int diagonal = triangle[j][k] + firstRow[k+1];
                secondRow[k] = min (neeche,diagonal);
            }
            firstRow = secondRow;
        }
        return firstRow[0];
    }
};
