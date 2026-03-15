class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        queue <string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int count = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr==target) return count;
                for (int i = 0; i<4; i++)
                {
                    string up = curr;
                    string down = curr;
                    up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                    down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;
                    if (!dead.count(up) && !visited.count(up))
                    {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!dead.count(down) && !visited.count(down))
                    {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            count += 1;
        }
        return -1;
    }
};
