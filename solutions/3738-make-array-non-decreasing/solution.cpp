class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1) return 1;

        stack<int> stk;
        stk.push(nums[n-1]);

        int decrease = 0;
        for (int i = n-2; i>=0; i--)
        {

            while (!stk.empty() && nums[i]>stk.top())
            {
                stk.pop();
                decrease++;
            }
            stk.push(nums[i]);
        }

        return n - decrease;
        
    }
};

//[4,2,5,3,5]

// stack = 5,3
//stack 5,2
//stack 4
