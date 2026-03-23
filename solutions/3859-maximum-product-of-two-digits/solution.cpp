class Solution {
public:
    int maxProduct(int num) 
    {
        vector<int> result;
        while (num > 0) {
            result.push_back(num % 10);
            num /= 10;
        }
        int n = result.size();
        reverse(result.begin(), result.end());
        sort(result.begin(),result.end());
        return result[n-1]*result[n-2];
    }
};
