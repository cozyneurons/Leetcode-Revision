class Solution {
    int countelements(vector<int> gums,int weight)
    {
        int member = 1;
        long long member_weight = 0;
        for (int i = 0; i<gums.size(); i++)
        {
            if (gums[i] + member_weight <= weight)
            {
                member_weight += gums[i];
            }
            else
            {
                member++;
                member_weight = gums[i];
            }
        }
        return member;
    }
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if (n<k) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int count = countelements(nums,mid);
            if (count>k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
