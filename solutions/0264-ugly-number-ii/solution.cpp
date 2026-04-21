class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> beautiful(n+1,-1);
        beautiful[0] = 0;
        beautiful[1] = 1;
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        for (int i = 2; i < n+1; i++)
        {
            int first = 2*beautiful[i2];
            int second = 3*beautiful[i3];
            int third = 5*beautiful[i5];

            int nextugly = min({first,second,third});
            beautiful[i] = nextugly;
            if (nextugly == first) i2++;
            if (nextugly == second) i3++;
            if (nextugly == third) i5++;
        }
        return beautiful[n];
    }
};
