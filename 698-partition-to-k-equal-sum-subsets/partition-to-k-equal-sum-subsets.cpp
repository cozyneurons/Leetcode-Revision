class Solution {
private:
    int sum;
    bool recursion(int ind, vector<int>& nums,vector<int>& track,int k,int ori_k,int req_sum)
    {
        // base case
        if (k==1) return true;
        int n = nums.size();
        // ek subset ban gaya -> target -> k-1 subsets
        if (req_sum==0)
        {
            if (recursion(0,nums,track,k-1,ori_k,sum/ori_k)) return true;
        }
        for (int i = ind; i<n; i++)
        {
            // already picked
            if (track[i]==1) continue;
            if (nums[i]>req_sum) continue;
            // pick
            track[i] = 1;
            if (recursion(i+1,nums,track,k,ori_k,req_sum-nums[i])) return true;
            track[i] = 0;
            if (req_sum==0) return false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sum = accumulate(nums.begin(),nums.end(),0);
        // recursion
        // vector track 
        vector<int> track(n,0);
        if (sum%k!=0) return false;
        sort(nums.rbegin(),nums.rend());
        return recursion(0,nums,track,k,k,sum/k);
    }
};
