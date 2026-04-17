class Solution {
private:
    int reversekarde(int x) 
    {
        int rev = 0;
        while (x != 0)
        {
            int digit = x % 10;

            if (rev > INT_MAX/10 || rev < INT_MIN/10)
            return 0;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> ump;
        int ans = INT_MAX;
        for (int i = 0; i<n; i++)
        {
            if (ump.find(nums[i])!=ump.end())
            {
                int j = ump[nums[i]];
                ans = min(ans,abs(j-i));
            }
            int reverseee = reversekarde(nums[i]);
            ump[reverseee] = i;
        }
        if (ans==INT_MAX) return -1;
        return ans;
    }
};
