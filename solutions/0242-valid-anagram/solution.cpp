class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> ump;

        for (char x : s)
            ump[x]++;

        for (char y : t) {
            ump[y]--;
            if (ump[y] < 0)
                return false;
        }

        return true;
    }
};
