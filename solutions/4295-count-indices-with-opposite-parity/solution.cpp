class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> odd(n,0);
        vector<int> even(n,0);

        vector<int> ans(n,0);
        int oddnum = 0;
        int evennum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] % 2 == 0)
            {
                even[i] = oddnum;
                evennum++;
            }
            else
            {
                odd[i] = evennum;
                oddnum++;
            }
        }
        for (int i = 0 ; i<n; i++)
        {
            if (nums[i]%2==0)
            {
                ans[i] = even[i];
            }
            else ans[i] = odd[i];
        }
        return ans;
    }
};
