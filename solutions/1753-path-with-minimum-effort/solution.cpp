class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 1e9));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == m-1 && c == n-1) return dist;
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int newdist = max(dist, abs(grid[nr][nc] - grid[r][c]));
                    if(newdist < distance[nr][nc])
                    {
                        distance[nr][nc] = newdist;
                        pq.push({newdist,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

