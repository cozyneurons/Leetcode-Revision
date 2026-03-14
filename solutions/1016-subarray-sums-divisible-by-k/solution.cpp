class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int preSum = 0, cnt = 0;

        for(int i = 0; i < nums.size(); i++) 
        {
            preSum += nums[i];
            int remove = ((preSum % k) + k) % k;
            if(mpp.count(remove)) cnt += mpp[remove];
            mpp[remove]++;
        }

        return cnt;
    }
};
