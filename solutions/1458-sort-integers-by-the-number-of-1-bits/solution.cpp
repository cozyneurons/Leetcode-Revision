class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<pair<int,int>> vec;
        for (int num : arr)
        {
            int res = 0;
            int j = num;
            while (j)
            {
                res += j % 2;
                j >>= 1;
            }
            vec.push_back({num, res});
        }
        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return (a.second == b.second) ? a.first < b.first : a.second < b.second;
        });
        vector<int> ans;
        for (auto &p : vec) ans.push_back(p.first);
        return ans;
    }
};
