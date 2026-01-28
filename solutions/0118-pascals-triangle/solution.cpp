class Solution {
public:
    vector<int> generateRows(int Row)
    {
        vector<int> row;
        long long rowans=1;
        row.push_back(rowans);
        for(int column = 1; column<Row; column++)
        {
            rowans = rowans*(Row-column);
            rowans = rowans/(column);
            row.push_back(rowans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for (int i = 1; i<=numRows; i++)
        {
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};
