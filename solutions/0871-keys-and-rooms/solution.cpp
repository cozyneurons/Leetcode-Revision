class Solution {
    void dfs(vector<vector<int>>& rooms, int start, vector<bool>& visited)
    {
        for (auto& node : rooms[start])
        {
            if (visited[node]) continue;
            visited[node] = true;
            dfs(rooms,node,visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited(n,false);
        visited[0] = true;
        dfs(rooms,0,visited);
        for (bool x: visited)
        {
            if (!x) return false;
        }
        return true;
    }
};
