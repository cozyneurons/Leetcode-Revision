class Solution {
public:
    int digitFrequencyScore(int n) 
    {
        unordered_map<int,int> ump;
        vector<int> numbers = {0,0,0,0,0,0,0,0,0,0};
        int n1 = n;
        while(n>0)
            {
                int div = n%10;
                ump[div]++;
                n/=10;
            }
        int sum = 0;
        while(n1>0)
            {
                int div1 = n1%10;
                if (numbers[div1]==0)
                {
                    sum = sum + div1*ump[div1];
                    numbers[div1] = 1;
                }
                n1/=10;
            }
        return sum;
    }
};
