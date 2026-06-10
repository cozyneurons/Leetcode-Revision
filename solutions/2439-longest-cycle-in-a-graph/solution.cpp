class Solution {
public:
    vector<bool> visited;
    vector<bool> inRecursion;
    vector<int> count;
    int ans = -1;

    void dfs(int node, vector<int>& edges, int depth)
    {
        visited[node] = true;
        inRecursion[node] = true;
        count[node] = depth;

        if (edges[node] != -1)
        {
            int next = edges[node];
            if (!visited[next])
            {
                dfs(next, edges, depth + 1);
            }
            else if (inRecursion[next]) // visited bhi hai, recursion mei bhi hai matlab cycle detected!!
            {
                ans = max(ans, depth - count[next] + 1);
            }
        }
        inRecursion[node] = false;
    }
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size();
        visited.resize(n, false);
        inRecursion.resize(n, false);
        count.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, edges, 0);
            }
        }
        return ans;
    }
};
