class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long sum1 = 0;
        long long sum2 = 0;
        bool zeroinnums1 = false;
        bool zeroinnums2 = false;
        for (int x : nums1)
        {
            if (x!=0)
            {
                sum1+=x;
            } 
            else
            {
                sum1+=1;
                zeroinnums1 = true;
            } 
        }
        for (int y : nums2)
        {
            if (y!=0)
            {
                sum2+=y;
            } 
            else
            {
                sum2+=1;
                zeroinnums2 = true;
            } 
        }
        if (sum1>sum2 && !zeroinnums2) return -1;
        if (sum2>sum1 && !zeroinnums1) return -1;
        return max(sum1,sum2);
    }
};
