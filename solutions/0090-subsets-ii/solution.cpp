class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        // take
        curr.push_back(nums[i]);
        dfs(i + 1, nums, curr, res);

        // not take
        curr.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        dfs(i + 1, nums, curr, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, nums, curr, res);
        return res;
    }
};
