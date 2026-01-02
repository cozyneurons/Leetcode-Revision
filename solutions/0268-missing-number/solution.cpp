class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;

        for (int x : nums) {
            ump[x]++;
        }

        for (int i = 0; i <= n; i++) {
            if (ump.find(i) == ump.end()) {
                return i;
            }
        }
        return -1;
    }
};
