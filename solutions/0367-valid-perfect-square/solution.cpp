class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int low = 1;
        int high = num;
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            if ((1LL*mid*mid)==num) return true;
            if ((1LL*mid*mid)>num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
