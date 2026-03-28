class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = -1;
        for (int i = 0; i<n; i++)
            {
                for (int j = 0; j<n; j++)
                    {
                        if ((nums[i]==1 && nums[j]==2) || (nums[i]==2 && nums[j]==1))
                        {
                            if (ans==-1) ans = abs(i-j);
                            else ans = min(ans,abs(i-j));
                        }
                    }
            }
        return ans;
        
    }
};
