class Solution {
private:
    int t[1001][1001];
    int recurr(int n1, int n2, string& s1, string& s2)
    {
        if (n1<0 || n2<0) return 0;
        if (t[n1][n2]!=-1) return t[n1][n2];
        if (s1[n1]==s2[n2])
        {
            return t[n1][n2] = 1 + recurr(n1-1,n2-1,s1,s2);
        }
        return t[n1][n2] = 0 + max(recurr(n1-1,n2,s1,s2),recurr(n1,n2-1,s1,s2));
    }
public:
    int longestPalindromeSubseq(string s1) 
    {
        int n1 = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n2 = s2.size();
        memset(t,-1,sizeof(t));
        return recurr(n1-1,n2-1,s1,s2);
    }
};
