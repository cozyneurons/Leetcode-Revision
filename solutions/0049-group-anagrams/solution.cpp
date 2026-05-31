class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int index = 0;
        unordered_map<string,int> ump;
        vector<vector<string>> ans;
        int n = strs.size();

        for (int i = 0; i < n; i++)
        {
            string curr = strs[i];
            sort(curr.begin(), curr.end());

            if (ump.find(curr) != ump.end())
            {
                ans[ump[curr]].push_back(strs[i]);
            }
            else
            {
                ump[curr] = index;
                ans.push_back({});
                ans[index].push_back(strs[i]);
                index++;
            }
        }
        return ans;
    }
};
