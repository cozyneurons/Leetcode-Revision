class Solution 
{
private:
    long long calci(int k, vector<int>& piles)
    {
        long long yeah_boi = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            yeah_boi += (piles[i] + k - 1) / k;
        }
        return yeah_boi;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            long long time = calci(mid, piles);  
            if (time <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
