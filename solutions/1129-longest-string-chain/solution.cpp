class Solution {
private:
    bool satisfy(string &s1,string &s2)
    {
        if (s1.size()!=s2.size()+1) return false;
        int pehla = 0;
        int dusra = 0;
        while (pehla < s1.size() && dusra < s2.size())
        {
            if (s1[pehla] == s2[dusra])
            {
                dusra++;
            }
            pehla++;
        }
        if (dusra==s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) 
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &s1, string &s2) 
        {
            return s1.size() < s2.size();
        });
        vector<int> dp (n,1);
        int maxi = 1;
        for (int i = 1; i<n; i++)
        {
            for (int j = 0; j<i; j++)
            {
                if (satisfy(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
};
