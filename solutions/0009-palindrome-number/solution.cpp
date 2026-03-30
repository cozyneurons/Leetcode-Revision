class Solution {
public:
    bool isPalindrome(int x) 
    {
        string s = to_string(x);
        string y = s;
        reverse(s.begin(),s.end());
        if (s==y) return true;
        return false;
    }
};
