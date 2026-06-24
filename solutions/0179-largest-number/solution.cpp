class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums1;
        for (int num : nums) 
        {
            nums1.push_back(to_string(num));
        }
        auto myCompare = [](const string& s1, const string& s2) 
        {
            return s1 + s2 > s2 + s1;
        };
        sort(nums1.begin(), nums1.end(), myCompare);
        string ans;
        for (string& s : nums1) 
        {
            ans+=s;
        }
        if (ans[0]=='0') return "0";
        return ans;
    }
};
