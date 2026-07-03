class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int ans = 0;
        int faah = 0;
        unordered_set<int> st (begin(banned),end(banned));
        for (int i = 1; i<=n; i++)
        {
            if (st.find(i)!=st.end()) continue;
            if (ans + i <= maxSum)
            {
                ans += i;
                faah++;
            } 
        }
        return faah;
    }
};
