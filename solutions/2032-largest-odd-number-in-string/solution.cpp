class Solution {
public:
    string largestOddNumber(string num) 
    {
        int maxi = INT_MIN;
        int n = num.size();
        for (int i = n-1; i>=0; i--)
        {
            if ((num[i]-'0')%2!=0)
            {
                maxi = i;
                break;
            } 
        }
        if (maxi==INT_MIN) return "";
        string ans;
        for (int j = 0; j<=maxi; j++) ans.push_back(num[j]);
        return ans;
    }
};
