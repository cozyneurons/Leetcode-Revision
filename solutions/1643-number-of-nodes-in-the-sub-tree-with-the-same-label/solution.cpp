class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    void dfs(int node, int parent, string& labels, vector<int>& freq)
    {
        int before = freq[labels[node] - 'a'];
        freq[labels[node] - 'a']++;
        for (int nod : adj[node])
        {
            if (nod == parent) continue;
            dfs(nod, node, labels, freq);
        }
        int after = freq[labels[node] - 'a'];
        ans[node] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        ans.resize(n);
        adj.resize(n);
        vector<int> freq(26, 0);
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, labels, freq);
        return ans;
    }
};
