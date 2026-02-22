class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> seen;
    int dup = 0;

    for (int x : nums) 
    {
        if (seen.count(x)) {
            dup ^= x;
        } 
        else 
        {
            seen.insert(x);
        }
    }

    return dup;
    }
};
