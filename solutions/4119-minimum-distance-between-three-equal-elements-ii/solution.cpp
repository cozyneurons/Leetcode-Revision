class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,vector<int>> ump;
        for (int i = 0; i<n; i++)
        {
            ump[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto &p : ump)
        {
            int element = p.first;
            vector<int> temp = p.second;
            if (temp.size()>=3)
            {
                for (int i = 2; i<temp.size();i++)
                {
                    int distance = abs(temp[i]-temp[i-1]) + abs(temp[i-1]-temp[i-2]) + abs(temp[i]-temp[i-2]);
                    ans = min (ans,distance);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
