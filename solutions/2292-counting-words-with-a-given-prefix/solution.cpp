class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int n = words.size();
        int m = pref.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (words[i].size() < m) continue;
            bool found = true;
            for (int j = 0; j < m; j++)
            {
                if (words[i][j] != pref[j]) 
                {
                    found = false;
                    break;
                }
            }
            if (found) ans++;
        }
        return ans;
    }
};
