class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> result(n+1,0);
        for (int i = 0; i<n+1; i++)
        {
            int res = 0;
            int j = i;
            while(j)
            {
                res += j%2;
                j = j >> 1;
            }
            result[i] = res;
        }
        return result;
    }
};
