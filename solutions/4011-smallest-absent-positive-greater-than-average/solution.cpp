class Solution {
public:
    int smallestAbsent(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)
        {
            if (nums[0]>0) return nums[0] + 1;
            else return 1;
        }
        long long sum = 0;
        for (int x : nums) sum += x;
        double avg = (double)floor(sum/n);
        unordered_set <int> present;
        for(int x : nums) present.insert(x);

        int candidate = max(1, (int)floor(avg) + 1);
        while(true)
        {
            if (present.find(candidate)==present.end()) return candidate;
            candidate++ ;
        }
    }
};
