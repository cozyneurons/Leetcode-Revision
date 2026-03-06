class Solution {
private:
    int makeBouquet(vector<int>& bloomDay, int mid, int k)
    {
        int bouquets = 0;
        int flowers = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                flowers++;
                if (flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        return bouquets;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int makeBunch = makeBouquet(bloomDay, mid, k);

            if (makeBunch >= m)
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
