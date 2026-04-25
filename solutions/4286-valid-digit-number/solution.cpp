class Solution {
public:
    bool validDigit(int n, int x) 
    {
        bool contains = false;
        bool first = false;
        while(n>0)
            {
                int rem = n%10;
                if (rem==x) contains = true;
                int num = n/10;
                if (num==0)
                {
                    if (n==x) first = true;
                }
                n/=10;
            }
        if (contains && !first) return true;
        return false;
    }
};
