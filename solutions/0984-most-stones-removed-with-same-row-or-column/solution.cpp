class Solution {
    void dfs(vector<vector<int>>& stones, vector<int>& visited, int index)
    {
        visited[index]=1;
        int row = stones[index][0];
        int col = stones[index][1];
        for (int i = 0; i<stones.size(); i++)
        {
            if (visited[i]==1) continue;
            if (stones[i][0]==row || stones[i][1]==col)
            {
                dfs(stones,visited,i);
            }
            
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        int groups = 0;
        vector<int> visited(n,0);
        for (int i = 0; i<n; i++)
        {
            if (visited[i]==1) continue;
            dfs(stones,visited,i);
            groups++;
        }
        return n - groups;                                          
    }
};
