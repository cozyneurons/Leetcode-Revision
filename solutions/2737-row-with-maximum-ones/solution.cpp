class Solution{
    public:
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int max_count = 0, index = 0;

    for (int i = 0; i < mat.size(); i++) {
        int ones = 0;
        for (int val : mat[i]) {
            ones += val;
        }

        if (ones > max_count) {
            max_count = ones;
            index = i;
        }
    }
    return {index, max_count};
}
};
