class Solution {
private:
    int daysRequired(vector<int>& weights, int capacity)
    {
        int days = 1;
        int load = 0;

        for (int w : weights)
        {
            if (load + w <= capacity)
            {
                load += w;
            }
            else
            {
                days++;
                load = w;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int total = 0;
        int maxi = 0;
        for (int i =0; i<n; i++)
        {
            maxi = max (maxi,weights[i]);
            total+=weights[i];
        }
        int low = maxi;
        int high = total;
        int cap = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int req = daysRequired(weights,mid);
            if (req<=days)
            {
                cap = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return cap;
    }
};
