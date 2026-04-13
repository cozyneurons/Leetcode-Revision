class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_map<string,int> ump;
        for (string bankGene : bank)
        {
            ump[bankGene]++;
        }
        unordered_map<string,int> visited;
        vector<char> chars = {'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({startGene,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            string currentGene = it.first;
            int level = it.second;
            if (visited.find(currentGene) != visited.end()) continue;
            visited[currentGene] = 1;
            for (int i = 0; i < 8; i++)
            {
                char original = currentGene[i];
                for (char thisChar : chars)
                {
                    if (thisChar == original) continue;
                    currentGene[i] = thisChar;
                    if (ump.find(currentGene) != ump.end())
                    {
                        if (currentGene == endGene) return level + 1;
                        q.push({currentGene, level + 1});
                    }
                }
                currentGene[i] = original;
            }
        }
        return -1;
    }
};
