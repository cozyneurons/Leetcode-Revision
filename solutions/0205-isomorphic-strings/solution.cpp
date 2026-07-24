class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int n = s.length();
        unordered_map<char,char> umps;
        unordered_map<char,char> umpt;

        for (int i = 0; i<n; i++)
        {
            if (umps.find(s[i])!=umps.end())
            {
                if (umps[s[i]]!=t[i]) return false;
            }
            else
            {
                umps[s[i]] = t[i];
            }
            if (umpt.find(t[i])!=umpt.end())
            {
                if (umpt[t[i]]!=s[i]) return false;
            }
            else
            {
                umpt[t[i]] = s[i];
            }
        }
        return true;
    }
};
