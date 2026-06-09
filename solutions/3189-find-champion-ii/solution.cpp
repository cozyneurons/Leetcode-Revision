class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int> freq(n,0);
        int sz = edges.size();
        for (int i = 0; i<sz; i++)
        {
            freq[edges[i][1]]++;
        }
        int do_baar = 0;
        int ans = -1;
        for (int i = 0; i<n; i++)
        {
            if (freq[i]==0)
            {
                do_baar++;
                ans = i;
            }
        }
        if (do_baar>=2) return -1;
        return ans;
    }
};
