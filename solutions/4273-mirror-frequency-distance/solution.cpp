class Solution {
public:
    int mirrorFrequency(string s) 
    {
        unordered_map<char,int> ump;
        int n = s.size();
        for (char c : s)
            {
                ump[c]++;
            }
        int ans = 0;
        bool visited[256] = {false};
        for (char c : s)
            {
                if (visited[c]) continue;
                char m;
                if (islower(c))
                {
                    m = 'a' + 'z' - c;
                }
                else m = '0' + '9' - c;
                if (ump.find(c)!=ump.end() && ump[c])
                {
                    int freqc = ump[c];
                    int freqm = 0;
                    if (ump.find(m)!=ump.end() && ump[m])
                    {
                        freqm = ump[m];
                    }
                    ans += abs(freqc-freqm);
                }
                visited[c] = true;
                visited[m] = true;
            }
        return ans;
    }
};
