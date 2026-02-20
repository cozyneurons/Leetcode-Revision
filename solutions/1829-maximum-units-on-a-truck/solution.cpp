class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int m = boxTypes.size();
        int n = boxTypes[0].size();
        int maxi = 0;
        sort(boxTypes.begin(), boxTypes.end(),
        [](auto& a, auto& b)
        {
            return a[1] > b[1];
        });
        for (int i = 0; i<m; i++)
        {
            if ((truckSize - boxTypes[i][0])>=0)
            {
                maxi += boxTypes[i][1]*boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                while (truckSize!=0)
                {
                    maxi += boxTypes[i][1];
                    truckSize -= 1 ;
                }
            }
        }
        return maxi;
    }
};
