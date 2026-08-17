class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = prices.size();
        while (left<n && right<n)
        {
            if (prices[left]>=prices[right])
            {
                left = right;
                right++;
            }
            else
            {
                ans = max(prices[right]-prices[left],ans);
                right++;
            }
        }
        return ans;
    }
};