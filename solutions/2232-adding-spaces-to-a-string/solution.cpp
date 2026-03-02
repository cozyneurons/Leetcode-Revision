class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string result;
        int j = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (j < spaces.size() && i == spaces[j])
            {
                result.push_back(' ');
                j++;
            }
            result.push_back(s[i]);
        }
        return result;
    }
};
