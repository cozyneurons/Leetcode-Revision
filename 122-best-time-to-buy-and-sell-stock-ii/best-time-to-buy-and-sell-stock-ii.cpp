class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ahead_buy = 0;
        int ahead_notbuy = 0;
        for (int ind = n-1; ind>=0;ind--) 
        {
            // jab buy kar sakte hai 
            // i) toh buy kar lete hai, aur aage jake sell kardenge(-prices[ind] + ahead_notbuy), usska profit le lenge
            // ii) toh buy nhii karte hai chalo, aage jake buy karenge(ahead_buy)
            int curr_buy = max(-prices[ind] + ahead_notbuy, ahead_buy);

            // jab sell kar sakte hai 
            // i) toh sell kar lete hai, aur aage jake firr buy karenge (ahead_notbuy), usska profit le lenge
            // ii) toh sell nhii karte hai chalo, aage jake sell karenge(ahead_notbuy)

            int curr_notbuy = max(prices[ind] + ahead_buy, ahead_notbuy);

            ahead_buy = curr_buy;
            ahead_notbuy = curr_notbuy;
        }
        return ahead_buy;
    }
};