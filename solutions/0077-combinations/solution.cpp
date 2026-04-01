class Solution {
private:
    void combination(int start, vector<int>& temp, vector<vector<int>>& ans, int n, int k)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n - (k - temp.size()) + 1; i++)
        {
            temp.push_back(i);
            combination(i + 1, temp, ans, n, k);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(1, temp, ans, n, k);
        return ans;
    }
};
