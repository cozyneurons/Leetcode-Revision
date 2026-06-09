class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int ans = 0;
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i<n; i++)
        {
            for (int j = i + 1; j<n; j++)
            {
                int weight = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,weight});
                adj[j].push_back({i,weight});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> inMST(n,false);
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;
            if (inMST[node]) continue;
            inMST[node] = true;
            ans+=weight;
            for (auto neigh : adj[node])
            {
                int neighbour = neigh.first;
                int neighbour_weight = neigh.second;
                if (inMST[neighbour]) continue;
                pq.push({neighbour_weight,neighbour});
            }
        }
        return ans;

    }
};
