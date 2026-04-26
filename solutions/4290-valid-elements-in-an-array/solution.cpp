class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        
        vector<bool> toto(n,false);

        int prev = INT_MIN;
        for (int i = 0; i<n; i++)
            {
                if (nums[i]>prev)
                {
                    toto[i] = true;
                    prev = nums[i];
                }
            }
        int prev2 = INT_MIN;
        for (int i = n-1; i>=0; i--)
            {
                if (nums[i]>prev2)
                {
                    toto[i] = true;
                    prev2 = nums[i];
                }
            }
        for (int i = 0; i<n; i++)
            {
                if (toto[i]==true)
                {
                    ans.push_back(nums[i]);
                }
            }
        return ans;
    }
};
