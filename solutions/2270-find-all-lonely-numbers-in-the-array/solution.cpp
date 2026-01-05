class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        vector <int> ans;
        unordered_map <int, int> ump;
        for (int x : nums)
        {
            ump[x]++;
        }
        for (auto &[x, freq] : ump) {
            if (freq == 1 &&
                ump.find(x - 1) == ump.end() &&
                ump.find(x + 1) == ump.end()) 
            {
                ans.push_back(x);
            }
        }

        return ans;  
    }
};
