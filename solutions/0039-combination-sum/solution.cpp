class Solution {
public:
    void dfs(int idx, vector<int>& a, int target,
             vector<int>& curr, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }

        if (idx == a.size() || target < 0) return;
        curr.push_back(a[idx]);
        dfs(idx, a, target - a[idx], curr, res);
        curr.pop_back();
        dfs(idx + 1, a, target, curr, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(0, candidates, target, curr, res);

        return res;
    }
};
