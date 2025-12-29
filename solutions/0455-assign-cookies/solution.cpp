class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int Children = 0;
        int cookie = 0;
        while (cookie < s.size() && Children < g.size()) {
            if (s[cookie] >= g[Children]) {
                Children++;
            }
            cookie++;
        }
        return Children;
    }
};
