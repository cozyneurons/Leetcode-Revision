class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) 
    {
        int n = capacity.size();
        int result = -1;
        int prevCapacity = INT_MAX;
        for (int i = 0; i<n; i++)
        {
            if (capacity[i]>=itemSize && capacity[i]<prevCapacity) 
            {
                prevCapacity = capacity[i];
                result = i;
            }
        }
        return result;
    }
};
