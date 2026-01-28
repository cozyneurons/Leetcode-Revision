class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int>row;
        row.push_back(1);
        long long ans = 1;
        for (int col=1; col<rowIndex+1; col++)
        {
            ans = ans*(rowIndex+1-col);
            ans = ans/col;
            row.push_back(ans);
        }
        return row;
    }
};
