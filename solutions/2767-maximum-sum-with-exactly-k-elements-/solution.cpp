class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(k--)
        {
            ans += high;
            high++;
        }

        return ans;
    }
};
