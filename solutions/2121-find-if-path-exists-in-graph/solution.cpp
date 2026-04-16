class Solution {
private:
    bool dfs(unordered_map<int,vector<int>>& adj, int source, int destination, vector<bool>& visited)
    {
        if (source == destination) return true;
        if (visited[source]) return false;
        visited[source] = true;
        for (auto& x: adj[source])
        {
            if (dfs(adj, x, destination, visited))
                return true;
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int,vector<int>> adj;
        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(adj, source, destination, visited);
    }
};
