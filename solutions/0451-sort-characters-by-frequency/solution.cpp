class Solution {
public:
    string frequencySort(string s) 
    {
        int n = s.size();
        map<char,int> freq;
        for (int i = 0; i<n; i++)
        {
            freq[s[i]]++;
        }
        vector<pair<char,int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](pair<char,int>& a, pair<char,int>& b){
        return a.second > b.second;
        });
        string ans;
        for(auto &p : v)
        {
            char c = p.first;
            int count = p.second;
            while (count--)
            {
                ans.push_back(c);
            }
        }
        return ans;   
    }
};
