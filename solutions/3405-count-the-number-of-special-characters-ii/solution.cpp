class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int count = 0;
        unordered_map<char,int> ump;
        int n = word.size();
        for (int i = n-1; i>=0; i--)
        
        {
            if (int(word[i])>=97 && int(word[i])<=122)
            {
                if (ump.find(word[i])==ump.end())
                {
                    ump[word[i]] = i;
                }
            }
        }
        for (int i = 0; i<n; i++)
        {
            if (int(word[i])<=97)
            {
                if (ump.find(word[i])==ump.end())
                {
                    ump[word[i]] = i;
                }
            }
        }
        for (char ch = 'a'; ch<='z'; ch++)
        {
            if (ump.find(ch)!=ump.end())
            {
                char upper = toupper(ch);
                if (ump.find(upper)!=ump.end())
                {
                    if (ump[ch]<ump[upper]) count++;
                }
            }
        }
        return count;
    }
};
