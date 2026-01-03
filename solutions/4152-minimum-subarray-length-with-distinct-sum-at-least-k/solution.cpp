class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        vector<int> drelanvixo = nums;
        unordered_map<int,int> freq;
        int l = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            if (freq[nums[r]] == 0) sum += nums[r];
            freq[nums[r]]++;

            while (sum >= k) {
                ans = min(ans, r - l + 1);
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) sum -= nums[l];
                l++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
