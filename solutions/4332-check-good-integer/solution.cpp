class Solution {
public:
    bool checkGoodInteger(int n) 
    {
        long long digitSum = 0;
        long long squareSum = 0;
        while(n>0)
            {
                digitSum += n%10;
                squareSum += (n%10)*(n%10);
                n/=10;
            }
        if ((squareSum-digitSum)>=50)return true;
        return false;
    }
};
