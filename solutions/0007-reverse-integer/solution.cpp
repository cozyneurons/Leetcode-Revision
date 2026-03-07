class Solution {
public:
    int reverse(int x) 
    {
        long long rev = 0;
        bool is_negative = false;
        if (x < 0) is_negative = true;
        long long num = llabs((long long)x);
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if(rev > INT_MAX) return 0;
        return is_negative ? -rev : rev;
    }
};
