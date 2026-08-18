class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> after(2, 0);
        vector<int> after2(2, 0); 
        vector<int> curr(2, 0);   
        for (int ind=n-1; ind>=0; ind--) 
        {
            curr[1] = max(-prices[ind] + after[0], after[1]);
            curr[0] = max(prices[ind] + after2[1], after[0]);
            after2 = after;
            after = curr;
        }
        return after[1];
    }
};
