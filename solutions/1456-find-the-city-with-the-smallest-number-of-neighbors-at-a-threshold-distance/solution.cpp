class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {

        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++) cost[i][i] = 0;
        for (auto it : edges)
        {
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] = it[2];
        }
        for (int k = 0; k<n; k++)
        {
            for (int i =0; i<n; i++)
            {
                for (int j = 0; j<n; j++)
                {
                    if(cost[i][k] != 1e9 && cost[k][j] != 1e9) cost[i][j] = min (cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        int cityNumber = 0;
        int minans = INT_MAX;
        for (int i = 0; i<n; i++)
        {
            
            int city_neighbours = 0;
            for (int j = 0; j<n; j++)
            {
                if (cost[i][j]<=distanceThreshold) city_neighbours++;
            }
            if (city_neighbours<=minans)
            {
                minans = min(minans,city_neighbours);
                cityNumber = i;
            }
        }
        return cityNumber;

    }
};
