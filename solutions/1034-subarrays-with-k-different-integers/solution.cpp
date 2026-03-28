class Solution {
private:
    int atMostk(vector<int>& nums, int k)
    {
        unordered_map <int,int> mpp;
        int low = 0;
        int n = nums.size();
        
        int ans = 0;
        for (int high = 0; high<n; high++)
        {
            mpp[nums[high]]++;
            while (mpp.size()>k && low<n)
            {
                mpp[nums[low]]--;
                if (mpp[nums[low]]==0) mpp.erase(nums[low]);
                low++;
            }
            ans = ans + high - low ;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostk(nums,k) - atMostk(nums,k-1);
    }
};

