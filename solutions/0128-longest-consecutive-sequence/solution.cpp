class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set <int> st;
        for (int i = 0 ; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        int maxi = 0;
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int x = it;
                int cnt = 1;
                while (st.find(x+1)!=st.end())
                {
                    x++;
                    cnt++;
                }
                maxi = max(cnt,maxi);
            }
        }
        return maxi;
    }
};
