class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        if (n <= 1) return 0;
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < n; i++)
        {
            ump[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return steps;
                int left = curr - 1;
                int right = curr + 1;
                if (left >= 0 && !visited[left])
                {
                    visited[left] = true;
                    q.push(left);
                }
                if (right < n && !visited[right])
                {
                    visited[right] = true;
                    q.push(right);
                }
                int val = arr[curr];
                if (ump.count(val))
                {
                    for (int ele : ump[val])
                    {
                        if (!visited[ele])
                        {
                            visited[ele] = true;
                            q.push(ele);
                        }
                    }
                    ump.erase(val);
                }
            }
            steps++;
        }
        return -1;
    }
};
