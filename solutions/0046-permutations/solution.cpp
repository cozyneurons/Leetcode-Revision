class Solution {
private:
    void permutations(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp,vector<int>& seen, int n)
    {
        if (temp.size() == n)
        {
            ans.push_back(temp);
        }
        for(int i = 0; i<n; i++)
        {
            if (seen[i]) continue;
            temp.push_back(nums[i]);
            seen[i] = 1;
            permutations(ans,nums,temp,seen,n);
            temp.pop_back();  
            seen[i] = 0; 
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> seen(n,0);
        permutations (ans,nums,temp,seen,n);
        return ans;
    }
};
