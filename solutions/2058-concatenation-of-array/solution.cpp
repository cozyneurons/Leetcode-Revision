class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> gums(2 * n);

        for (int i = 0; i < n; i++) {
            gums[i] = nums[i];
            gums[i + n] = nums[i];
        }
        return gums;
    }
};
