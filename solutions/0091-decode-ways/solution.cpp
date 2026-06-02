class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // dp[i] ka matlab hai no. of. ways to decode from i to n
        dp[n] = 1; // neeche pahuch gaye, ek valid tareeka mil gaya

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }
            // ek digit ke liye
            dp[i] = dp[i + 1];

            // do digit ke liye
            if (i != n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0]; 
    }
};
