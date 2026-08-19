class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,int> ump;
        int index = 0;
        vector<vector<string>> ans;
        int n = strs.size();
        for (int i = 0; i<n; i++)
        {
            string curr = strs[i];
            sort(curr.begin(),curr.end());
            if (ump.find(curr)==ump.end())
            {
                ump[curr] = index;
                ans.push_back({});
                ans[index].push_back(strs[i]);
                index++;

            }
            else
            {
                ans[ump[curr]].push_back(strs[i]);
            }
        }
        return ans;
    }
};

// aet = 0
// ant = 1
// abt = 2
// index = 2
//{{eat,tea,ate},{tan,nat},{bat}}
// 3 things
