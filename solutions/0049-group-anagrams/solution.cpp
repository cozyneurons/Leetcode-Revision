class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto it:strs)
        {
            string word=it;
            sort(it.begin(),it.end());
            mpp[it].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
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

