class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long prev = 0;
        for (int x : nums) 
        {
            if (x==prev) continue;
            long long gap = x-prev-1;
            if (gap > 0) 
            {
                long long take = min((long long)k, gap);

                long long first=prev+1;
                long long last=prev+take;

                ans+=(first+last)*take/2;
                k-=take;
                if (k==0) return ans;
            }
            prev = x;
        }
        if (k>0) 
        {
            long long first = prev+1;
            long long last = prev+k;
            ans+=(first+last)*k/2;
        }
        return ans;
    }
};
