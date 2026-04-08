class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if (n==1) return false;
        int current_sum = 0;
        unordered_map<int, int> ump;
        ump[0] = -1;
        for (int j = 0; j<n; j++)
        {
            current_sum+=nums[j];
            int remainder = current_sum%k;
            if (ump.find(remainder)!=ump.end())
            {
                if (abs(ump[remainder]-j)>=2) return true;  
            }
            else ump[remainder] = j;
        }
        return false;
    }
};
