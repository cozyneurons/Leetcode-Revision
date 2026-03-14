class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        unordered_map<int,int> ump;
        int presum = 0;
        int count = 0;
        ump[0] = 1;
        for (int i = 0; i<n; i++)
        {
            presum += nums[i];
            int remove = presum - goal;
            count += ump[remove];
            ump[presum] += 1;
        }
        return count;
    }
};

