class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long low = 0;
        long long high = sqrt(c);
        while(low<=high)
        {
            if ( (low*low + high*high) == c) return true;
            else if ( (low*low + high*high) < c) low++;
            else if ( (low*low + high*high) > c) high--;
        }
        return false;
    }
};

// c = 5;
// low = 0, high = 2;
// sum = 0*0 + 2*2 = 4<5
// 

