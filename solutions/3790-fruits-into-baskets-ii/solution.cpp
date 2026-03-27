class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if (fruits[i]<=baskets[j] && baskets[j]!=-1)
                {
                    baskets[j] = -1;
                    break;
                }
            }
        }
        int ans = 0;
        for (int k = 0; k<n; k++)
        {
            if (baskets[k]!=-1) ans++;
        }
        return ans;
    }
};
