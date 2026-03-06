class Solution {
private:
    long long requiredTime(vector<int>& piles, int k)
    {
        long long tem = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            tem += ((long long)piles[i] + k - 1) / k;
        }

        return tem;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high)
        {
            int k = low + (high - low) / 2;

            long long reqTime = requiredTime(piles, k);

            if (reqTime <= h)
            {
                ans = k;
                high = k - 1;
            }
            else
            {
                low = k + 1;
            }
        }

        return ans;
    }
};
