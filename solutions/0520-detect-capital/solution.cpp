class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int count = 0;
        int n = word.size();
        for (int i = 0; i<n; i++)
        {
            if (word[i] >= 65 && word[i] <= 90) count++;
        }
        if (count==n) return true;
        else if (count==0) return true;
        else if (count==1)
        {
            if (word[0] >= 65 && word[0] <= 90) return true;
        }
        return false;
        
    }
};
