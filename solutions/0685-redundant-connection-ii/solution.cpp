class DSU{
public:
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n+1);
        for (int i = 1; i<=n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu==pv) return false; // cycle milgaya
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();

        vector<int> parent(n+1);
        for (int i = 1; i<=n; i++)
        {
            parent[i] = i;
        }
        vector<int> edge1;
        vector<int> edge2;
        for (auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (parent[v]==v)
            {
                parent[v] = u;
            }
            else
            {
                edge1 = {parent[v],v};
                edge2 = edge;
                edge[1] = 0;
            }

        }
        DSU dsu(n);

        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (v==0) continue;
            if(!dsu.Union(u,v)) // cycle milgaya
            {
                if (!edge1.empty())
                {
                    return edge1;
                }
                return edge;
            }
        }
        return edge2;

    }
};
