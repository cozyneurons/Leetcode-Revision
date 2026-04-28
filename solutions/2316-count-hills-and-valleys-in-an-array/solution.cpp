class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> a;
        for (int x : nums)
        {
            if (a.empty() || x != a.back()) a.push_back(x);
        }

        int count = 0;
        int n = a.size();

        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) count++;
            if (a[i] < a[i-1] && a[i] < a[i+1]) count++;
        }

        return count;
    }
};
