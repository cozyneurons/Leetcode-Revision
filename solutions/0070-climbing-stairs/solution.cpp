class Solution {
public:
    int climbStairs(int n) 
    {
        int prev2 = 0;
        int prev = 1;
        int curr = 0;
        for(int i = 1; i<=n; i++)
        {
            curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
