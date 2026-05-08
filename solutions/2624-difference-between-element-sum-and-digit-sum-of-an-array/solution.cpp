class Solution {
private:
    int digitsum(int n)
    {
        int dsum = 0;
        while (n>0)
        {
            dsum += n%10;
            n/=10;
        }
        return dsum;
    }
public:
    int differenceOfSum(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int digsum = 0;
        for (int i = 0; i<n; i++)
        {
            sum += nums[i];
            digsum += digitsum(nums[i]);
        }
        return abs(sum-digsum);
    }
};
