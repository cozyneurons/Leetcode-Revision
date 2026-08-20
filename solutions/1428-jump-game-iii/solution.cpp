class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n = arr.size();
        vector<int> visited(n,-1);
        queue<int> q;
        q.push(start);
        bool ans = false;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (arr[curr]==0)
            {
                ans = true;
                break;
            }
            if (visited[curr]==1) continue;
            if (curr+arr[curr]<=n-1) q.push(curr+arr[curr]);
            if (curr-arr[curr]>=0) q.push(curr-arr[curr]);
            visited[curr] = 1;
        }
        return ans;
    }
};
