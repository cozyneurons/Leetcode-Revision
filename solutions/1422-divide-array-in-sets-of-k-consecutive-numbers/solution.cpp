class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int,int> freq;
        for(int x : nums) freq[x]++;
        for(auto it : freq)
        {
            int num = it.first;
            int count = it.second;
            if(count > 0)
            {
                for(int i = 0; i < k; i++)
                {
                    if(freq[num + i] < count) return false;
                    freq[num + i] -= count;
                }
            }
        }
        return true;
    }
};
