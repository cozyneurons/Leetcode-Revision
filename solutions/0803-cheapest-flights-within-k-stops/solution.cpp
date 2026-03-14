class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) adj[it[0]].push_back({it[1], it[2]});
        queue<pair<int,pair<int,int>>> q;
        vector<int> distance(n,1e9);
        q.push({0,{src,0}});
        distance[src] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;
            for(auto itr : adj[node])
            {
                int adjNode = itr.first;
                int price = itr.second;
                if(cost + price < distance[adjNode])
                {
                    distance[adjNode] = cost + price;
                    q.push({stops+1,{adjNode,distance[adjNode]}});
                }
            }
        }
        if(distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};
