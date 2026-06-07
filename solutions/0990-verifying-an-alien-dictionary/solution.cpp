class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            string a = words[i - 1];
            string b = words[i];
            int j = 0;
            while (j < a.size() && j < b.size())
            {
                if (mp[a[j]] < mp[b[j]])
                {
                    break;
                }
                if (mp[a[j]] > mp[b[j]])
                {
                    return false;
                }
                j++;
            }
            if (j == b.size() && a.size() > b.size())
            {
                return false;
            }
        }
        return true;
    }
};
