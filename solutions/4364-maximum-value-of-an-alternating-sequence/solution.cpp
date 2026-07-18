class Solution {
public:
    long long maximumValue(int n, int s, int m) 
    {
        if (n==1) return s;
        long long n_by_two = n/2;
        return s + m*n_by_two - (n_by_two - 1);
    }
};
