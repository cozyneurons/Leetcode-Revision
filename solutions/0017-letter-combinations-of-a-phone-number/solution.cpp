class Solution {
private:
    void backtrack(string digits, vector<string>& ans, unordered_map<char, string> ump, int i, string temp)
    {
        // base case
        if (i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string kuchpuch = ump[digits[i]];
        for (int j = 0; j<kuchpuch.size(); j++)
        {
            temp.push_back(kuchpuch[j]);
            backtrack(digits,ans,ump,i+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, string> ump{
    {'0',""},
    {'1',""},
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};
        vector<string> ans;
        backtrack(digits,ans,ump,0,"");
        return ans;
    }
};
