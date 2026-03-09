class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack <int> stk;
        unordered_map <int, int> ump;
        for (int i = 0; i<nums2.size(); i++)
        {
            while (!stk.empty() && stk.top()<nums2[i])
            {
                ump[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty())
        {
            ump[stk.top()] = -1;
            stk.pop();
        }
        vector <int> ans(nums1.size());
        for (int i = 0; i<nums1.size(); i++)
        {
            ans[i] = ump[nums1[i]];
        }
        return ans;
    }
};
