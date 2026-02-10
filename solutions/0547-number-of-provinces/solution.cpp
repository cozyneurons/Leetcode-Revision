class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int s = isConnected.size();
        vector<vector<int>> adj(s);
        vector<int> visited(s, 0);
        for (int i=0;i<s;i++)
        {
            for (int j=0; j<s; j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i = 0; i<s; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};
