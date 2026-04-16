class Solution {
    void dfs(vector<vector<int>>& graph, int start, int target,
             vector<vector<int>>& ans, vector<int>& temp)
    {
        temp.push_back(start);
        if (start == target)
        {
            ans.push_back(temp);
        }
        else
        {
            for (int node : graph[start])
            {
                dfs(graph, node, target, ans, temp);
            }
        }
        temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph, 0, n - 1, ans, temp);
        return ans;
    }
};
