class Solution {
public:
    int firstMatchingIndex(string s) 
    {
        int n = s.size();
        int i = 0;
        int ans = -1;
        while(i<n)
            {
                if (s[i]==s[n-i-1])
                {
                    if (ans==-1) ans = i;
                    else ans = min (ans,i);
                }
                i++;
            }
        return ans;
    }
};
