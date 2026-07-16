class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // adj
        vector<vector<int>> adj (numCourses);
        // queue
        queue<int> q;
        // indeg
        vector<int> indeg(numCourses,0);
        // topo 
        vector<int> topo;
        for (auto& it: prerequisites)
        {
            indeg[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i<numCourses; i++)
        {
            if (indeg[i]==0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto& neigh : adj[node])
            {
                if (indeg[neigh]>0)
                {
                    indeg[neigh]--;
                    if (indeg[neigh]==0) q.push(neigh);
                }
            }
        }
        return topo.size()==numCourses;
    }
};

// topo vector - saare nodes ka relation ki kon kiske pehle aana chayiye
// {2,4,6,1}.size ! = topo.size() return false

// kahns algo - bfs 
