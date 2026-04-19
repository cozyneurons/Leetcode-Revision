class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> maxscore(n,0);
        vector<int> minscore(n,0);
        
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int piche = n-1;
        for (int i = 0; i<n; i++)
            {
                maxi = max(maxi,nums[i]);
                maxscore[i] = maxi;

                mini = min(mini,nums[piche]);
                minscore[piche] = mini;

                piche--;
            }
        for(int i = 0; i<n; i++)
        {
            int instability = maxscore[i] - minscore[i];
            if (instability<=k) return i;
        }
        return -1;
    }
};
