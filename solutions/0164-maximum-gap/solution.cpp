class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2) return 0;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int prev = pq.top();
        pq.pop();
        int max_diff = 0;
        while(!pq.empty())
        {
            int curr = pq.top();
            pq.pop();
            max_diff = max(max_diff, curr - prev);
            prev = curr;
        }
        return max_diff;
    }
};
