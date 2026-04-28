class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        if (n==m)
        {
            if (haystack==needle) return 0;
            return -1;
        }
        for (int i = 0; i<n; i++)
        {
            if (n-i >= m)
            {
                string toto = haystack.substr(i, m);
                if (toto==needle) return i;
            }
            
        }
        return -1;
    }
};
