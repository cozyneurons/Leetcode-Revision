class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;

        vector<int> freq(26, 0);

        while(r<n)
        {
            freq[s[r] - 'A']++;
            int maxi = *max_element(freq.begin(), freq.end());
            if ((r-l+1-maxi)<=k) maxlen = max(maxlen,r-l+1);
            else
            {
                while ((r-l+1-maxi)>k)
                {
                    freq[s[l]-'A']--;
                    l++;
                }
            }
            r++;
        }
        return maxlen;
    }
};
