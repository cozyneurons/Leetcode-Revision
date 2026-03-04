class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set <char> st;
        int low = 0;
        int n = s.size();
        int ans = 0;
        for (int high = 0; high<n; high++)
        {
            while(st.find(s[high])!=st.end())
            {
                st.erase(s[low]);
                low++;
            }
            st.insert(s[high]);
            ans = max(high-low+1,ans);
        }
        return ans;
    }
};
