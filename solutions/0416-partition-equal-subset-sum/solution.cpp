class Solution {
private:
    int t[201][10001];
    bool solve(int index, int current_sum, int target, vector<int>& nums)
    {
        if (current_sum == target) return true;
        if (index >= nums.size() || current_sum > target) return false;
        if (t[index][current_sum] != -1) return t[index][current_sum];
        
        //pick karle
        bool pick = solve(index + 1, current_sum + nums[index], target, nums);

        // mat kar pick
        bool matkarPick = solve(index + 1, current_sum, target, nums);
        return t[index][current_sum] = (pick || matkarPick);
    }
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        memset(t,-1,sizeof(t));
        return solve(0,0,sum/2,nums);
    }
};
