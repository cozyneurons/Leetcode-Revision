class Solution {
private:
    void backtrack(string digits,vector<string> &ans,unordered_map<char, string> &ump,int level,string current)
    {
        if (level==digits.size())
        {
            ans.push_back(current);
        }
        char current_digit = digits[level];
        for (auto &x : ump[current_digit])
        {
            current.push_back(x);
            backtrack(digits,ans,ump,level+1,current);
            current.pop_back();
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
