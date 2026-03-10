class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n = strs.size();
        string s = strs[0];
        for (int i = 1; i<n; i++)
        {
            string compare;
            for (int j = 0; j<strs[i].size();j++)
            {
                if (s[j]==strs[i][j]) compare.push_back(s[j]);
                else break;
            }
            s = compare;
        }
        return s;
    }
};
