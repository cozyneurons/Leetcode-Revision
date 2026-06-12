class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        int sz = edges.size();
        vector<bool> indegree_not_zero(n,false);
        for (int i = 0; i<sz; i++)
        {
            indegree_not_zero[edges[i][1]] = true;
        }
        vector<int> ans;
        for (int j = 0; j<n; j++)
        {
            if (indegree_not_zero[j]==false) ans.push_back(j);
        }
        return ans;
    }
};
