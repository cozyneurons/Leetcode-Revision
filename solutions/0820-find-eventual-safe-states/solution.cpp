class Solution {
private:
    bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &check,vector<vector<int>>& adj)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it,visited,pathVisited,check,adj))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVisited[it]) return true;
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) 
        {
            for(int v : graph[i]) {
                adj[i].push_back(v);
            }
        }
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> check(n,0);
        for (int i = 0; i<n; i++)
        {
            if (!visited[i])
            {
                dfs(i,visited,pathVisited,check,adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i<n; i++)
        {
            if (check[i]) ans.push_back(i);
        }
        return ans;
    }
};
