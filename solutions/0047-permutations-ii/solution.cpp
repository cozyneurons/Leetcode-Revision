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
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1) return {{nums[0]}};
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> seen(n,0);
        permutations (ans,nums,temp,seen,n);
        sort(ans.begin(),ans.end());
        int n1 = ans.size();
        int i = 0;
        vector<vector<int>> realans;
        while (i<n1)
        {
            realans.push_back(ans[i]);
            while (i + 1 < n1 && ans[i] == ans[i + 1])
            {
                i++;
            }
            i++;
        }
        return realans;
    }
};
