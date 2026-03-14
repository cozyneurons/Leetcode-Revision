class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int> ump;
        int presum = 0;
        int count = 0;
        ump[0] = 1;
        for (int i = 0; i<n; i++)
        {
            presum += nums[i];
            int remove = presum - k;
            count += ump[remove];
            ump[presum] += 1;
        }
        return count;
    }
};
