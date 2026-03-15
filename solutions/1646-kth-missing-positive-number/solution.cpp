class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int start = 1;
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int kitnemissing = arr[mid] - (mid+1);
            if (kitnemissing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low + k;
    }
};
