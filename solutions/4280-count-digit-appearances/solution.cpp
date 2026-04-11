class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) 
    {
        unordered_map<int,int> ump;
        ump[digit] = 0;
        int n = nums.size();
        for (int i = 0; i<n; i++)
            {
                int number = nums[i];
                while(number)
                    {
                        int dig = number%10;
                        number/=10;
                        if (dig==digit) ump[digit]++;
                    }
            }
        return ump[digit];
    }
};
