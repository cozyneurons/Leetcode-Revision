class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        unordered_map <int,int> ump;
        vector<int> ans;
        for (int i = 0; i<nums.size(); i++)
        {
            smallest = min (smallest, nums[i]);
            largest = max (largest, nums[i]);
            ump.insert({nums[i],1});

        }
        for (int i = smallest; i<largest; i++)
        {
            if (ump.find(i)==ump.end()) ans.push_back(i);
        }
        return ans;
    }
};
