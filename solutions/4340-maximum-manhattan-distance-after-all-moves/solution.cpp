class Solution {
public:
    int maxDistance(string moves) 
    {
        int ans = 0;
        int n = moves.size();
        int u = 0;
        int d = 0;
        int l = 0;
        int r = 0;
        for (int i = 0; i<n; i++)
        {
            if (moves[i]=='U') u++;
            else if (moves[i]=='D') d++;
            else if (moves[i]=='L') l++;
            else if (moves[i]=='R') r++;
            else ans++;
        }
        return abs(r-l)+abs(u-d)+ans;
    }
};
