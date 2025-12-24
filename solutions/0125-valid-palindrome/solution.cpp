class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;

        for (unsigned char c : s) {
            if (isalnum(c)) {
                v.push_back(tolower(c));
            }
        }
        vector<char> rev = v;
        reverse(rev.begin(), rev.end());
        if (v == rev) return true;
        else return false;
    }

};
