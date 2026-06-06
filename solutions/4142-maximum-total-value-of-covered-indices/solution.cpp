class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) 
    {
        int n = nums.size();
        long long free = 0;
        long long occ = LLONG_MIN;
        for (int i = 0; i<n; i++)
            {
                long long newfree, newocc;
                if (s[i]=='0')
                {
                    newfree = max(free,occ);
                    newocc = LLONG_MIN;
                }
                else
                {
                    newocc = max(free,occ) + nums[i];
                    if (i>0)
                    {
                        newfree = free + nums[i-1];
                    }
                    else
                    {
                        newfree = LLONG_MIN;
                    }
                }
                free = newfree;
                occ = newocc;
            }
        return max(free,occ);
    }
};
