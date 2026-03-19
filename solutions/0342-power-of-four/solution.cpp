class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if (n==1) return true;
        int low = 0;
        int high = n/4;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if (pow(4,mid) == n) return true;
            else if (pow(4,mid) > n) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
