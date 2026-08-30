class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> ump;
        int i = 0;
        for (int i = 0; i<n; i++)
        {
            if (ump.find(nums[i])==ump.end())
            {
                ump[nums[i]] = i;
                ans++;
            }
            else if (ump[nums[i]]==-1)
            {
                continue;
            }
            else
            {
                if (ump[nums[i]]==i-1)
                {
                    ump[nums[i]] = i;
                }
                else
                {
                    ans--;
                    ump[nums[i]] = -1;
                }
            }
        }
        return ans;
    }
};
