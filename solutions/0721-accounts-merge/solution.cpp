class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) 
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
        {
            parent[i] = i;
        }
    }
    int find(int x) 
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) 
        {
            parent[pv] = pu;
        } 
        else if (rank[pv] > rank[pu]) 
        {
            parent[pu] = pv;
        } 
        else 
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> mailNode;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 1; j < accounts[i].size(); j++) 
            {
                string mail = accounts[i][j];
                if (mailNode.find(mail) == mailNode.end()) 
                {
                    mailNode[mail] = i;
                } 
                else 
                {
                    dsu.Union(i, mailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for (auto it : mailNode)
        {
            string mail = it.first;
            int root = dsu.find(it.second);
            mergedMail[root].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) 
        {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto mail : mergedMail[i]) 
            {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
