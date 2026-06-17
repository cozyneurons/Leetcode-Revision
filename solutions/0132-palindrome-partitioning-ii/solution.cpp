class Solution {
public:
    int t[2001];
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int f(int i, int n, string& s)
    {
        if(i == n) return t[i] = 0;
        if (t[i]!=-1) return t[i];
        int cost = INT_MAX;
        for(int j = i; j < n; j++)
        {
            if(isPalindrome(s, i, j))
            {
                cost = min(cost, 1 + f(j + 1, n, s));
            }
        }
        return t[i] = cost;
    }
    int minCut(string s)
    {
        memset(t,-1,sizeof(t));
        return f(0, s.size(), s) - 1;
    }
};
