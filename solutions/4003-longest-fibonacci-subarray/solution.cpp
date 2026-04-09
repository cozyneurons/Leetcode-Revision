class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1 || n==2) return n;
        int ans = 2;
        int first = nums[0];
        int second = nums[1];
        int j = 0;
        for(int i = 2; i<n; i++)
        {
            int third = first + second;
            if (third==nums[i])
            {
                ans = max(ans,i-j+1);
            }
            else j = i-1;
            first = second;
            second = nums[i];
        }
        return ans;
    }
};
