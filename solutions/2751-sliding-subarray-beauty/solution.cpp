class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        map<int,int> mpp;
        int i = 0, s = 0;
        for (int j = 0; j < n; j++)
        {
            mpp[nums[j]]++;

            if (j - i + 1 > k)
            {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            if (j - i + 1 == k)
            {
                int count = 0;
                int beauty = 0;

                for (auto &p : mpp)
                {
                    if (p.first < 0)
                    {
                        count += p.second;
                        if (count >= x)
                        {
                            beauty = p.first;
                            break;
                        }
                    }
                }
                ans[s++] = beauty;
            }
        }
        return ans;
    }
};
